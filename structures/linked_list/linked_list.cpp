// LINKED LIST
#include "node.cpp"
#include <iostream>
#include <map>
#include <string>
using std::cout;

template <typename T> class List {
private:
  Node<T> *front;
  Node<T> *back;
  int size{0};
  int capacity{10};

  void init(T data) {
    this->front = new Node(data);
    this->back = this->front;
    this->size++;
  }

public:
  List() {
    this->front = nullptr;
    this->back = nullptr;
  };
  List(int capasity) {
    this->capacity = capasity;
    this->front = nullptr;
    this->back = nullptr;
  };
  ~List() {
    Node<T> *curr = this->front;
    while (curr) {
      Node<T> *next = curr->next;
      delete curr;
      curr = next;
    }
  }
  int count() { return this->size; }
  Node<T> *get_front() { return this->front; };
  Node<T> *get_back() { return this->back; };
  void push_back(T data) {
    if (this->count() > capacity) {
      throw "Capacity error";
    }

    if (this->is_empty()) {
      this->init(data);
    } else {
      Node<T> *tempNode = new Node(data);
      this->back->next = tempNode;
      this->back = tempNode;
      this->size++;
    }
  }
  T pop_back() {
    if (this->is_empty()) {
      throw "List is empty!";
    }

    if (this->back == this->front) {
      return this->pop_front();
    }

    Node<T> *curNode = this->front;

    while (curNode->next != this->back)
      curNode = curNode->next;
    T data = this->back->data;
    delete this->back;
    this->back = curNode;
    this->back->next = nullptr;
    this->size--;

    return data;
  }
  T pop_front() {
    if (this->is_empty()) {
      throw "List is empty!";
    }

    T data = this->front->data;

    Node<T> *temp = this->front;
    this->front = temp->next;
    delete temp;
    this->size--;

    return data;
  };
  void push_front(T data) {
    if (this->count() > this->capacity) {
      throw "Capacity error";
    }

    if (this->is_empty()) {
      this->init(data);
    } else {
      Node<T> *newNode = new Node(data);
      newNode->next = this->front;
      this->front = newNode;
      this->size++;
    }
  }
  bool find(T data) {
    Node<T> *curNode = this->front;
    while (curNode != nullptr) {
      if (data == curNode->data) {
        return true;
      }
      curNode = curNode->next;
    }
    return false;
  }
  bool is_empty() { return this->front == nullptr; };
  void reverse() {
    if (this->front != nullptr) {
      Node<T> *prevNode = this->front;
      Node<T> *curNode = this->front->next;

      prevNode->next = nullptr;

      while (curNode != nullptr) {
        Node<T> *tempNode = curNode->next;
        curNode->next = prevNode;
        prevNode = curNode;
        curNode = tempNode;
      }

      this->front = prevNode;
    }
  }
  T operator[](int index) {
    Node<T> *curr = this->front;
    while (index != 0) {
      if (curr == nullptr) {
        return T();
      }
      curr = curr->next;
      index--;
    }
    return curr->data;
  }
};

int main() {

  cout << "LIST TYPE INTEGER"
       << "\n";
  List<int> list(10);
  cout << " is empty " << (list.is_empty() ? "true" : "false") << "\n";
  cout << " count " << (list.count()) << "\n";
  cout << " push_back 1 "
       << "\n";
  list.push_back(1);
  cout << " push_back 2 "
       << "\n";
  list.push_back(2);
  cout << " push_front 3 "
       << "\n";
  list.push_front(3);
  cout << " push_back 4 "
       << "\n";
  list.push_back(4);
  cout << " push_front 5 "
       << "\n";
  list.push_front(5);
  cout << " count " << (list.count()) << "\n";
  cout << " print list "
       << "\n";
  Node<int> *curr = list.get_front();
  while (curr) {
    cout << curr->data << "\t";
    curr = curr->next;
  }
  cout << "\n list[1] " << list[1] << "\n";
  cout << "list[10] " << list[10] << "\n";
  cout << "find 3 " << (list.find(3) ? "true" : "false") << "\n";
  cout << "find 23 " << (list.find(23) ? "true" : "false") << "\n";

  cout << " pop front " << list.pop_front() << "\n";
  cout << " pop pop_back " << list.pop_back() << "\n";
  cout << " pop pop_back " << list.pop_back() << "\n";
  cout << " print list "
       << "\n";
  curr = list.get_front();
  while (curr) {
    cout << curr->data << "\t";
    curr = curr->next;
  }
}