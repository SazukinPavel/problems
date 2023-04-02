// LINKED LIST
#include "node.cpp"
#include <iostream>
using std::cout;

template <typename T> class DoublyLinkedList {
private:
  Node<T> *front{nullptr};
  Node<T> *back{nullptr};
  int size;

  void init(Node<T> *newNode) {
    this->front = newNode;
    this->back = front;
  }

public:
  Node<T> *get_front() { return this->front; };
  Node<T> *get_back() { return this->back; };
  void push_back(T data) {
    Node<T> *newNode = new Node<T>(data);
    if (this->front == nullptr) {
      this->init(newNode);
    } else {
      newNode->prev = this->back;
      this->back->next = newNode;
      this->back = newNode;
    }
    this->size++;
  }
  T pop_back() {
    if (this->back == nullptr) {
      return T();
    }
    T data = this->back->data;
    this->back = this->back->prev;
    this->size--;
    return data;
  }
  T pop_front() {
    if (this->front == nullptr) {
      return T();
    }
    T data = this->front->data;
    this->front = this->front->next;
    this->size--;
    return data;
  };
  void push_front(T data) {
    Node<T> *newNode = new Node<T>(data);
    if (this->front == nullptr) {
      this->init(newNode);
    } else {
      this->front->prev = newNode;
      newNode->next = this->front;
      this->front = newNode;
    }
    this->size++;
  }
  void insert(int index, T data) {
    if (index > this->size || index < 0) {
      throw "Bad index!";
    }

    if (index == 0) {
      this->push_front(data);
    } else if (index == this->size) {
      this->push_back(data);
    } else {
      Node<T> *curr = this->front->next;
      int currIndex = 1;

      while (index > currIndex + 1) {
        curr = curr->next;
        currIndex++;
      }
      Node<T> *newNode = new Node<T>(data);

      newNode->prev = curr;
      newNode->next = curr->next;
      curr->next->prev = newNode;
      curr->next = newNode;

      this->size++;
    }
  }
  void remove(T data) {
    while (this->front->data == data) {
      this->front = this->front->next;
      this->front->prev = nullptr;
      this->size--;
    };

    Node<T> *curr = this->front;
    while (curr) {
      if (curr->data == data) {
        if (curr->next) {
          curr->next->prev = curr->prev;
        }
        if (curr->prev) {
          curr->prev->next = curr->next;
        }
      }
      curr = curr->next;
    }
  }
  bool find(T data) {
    Node<T> *curr = this->front;
    while (curr) {
      if (curr->data == data) {
        return true;
      }

      curr = curr->next;
    }
    return false;
  }
  bool is_empty() { return this->front == nullptr; };
  int count() { return this->size; }
  void reverse() {
    Node<T> *curr = this->back;

    this->front = this->back;

    while (curr) {
      Node<T> *temp = curr->prev;
      curr->prev = curr->next;
      curr->next = temp;
      curr = curr->next;
    }

    this->back = curr;
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
  DoublyLinkedList<int> list;
  cout << " is empty " << (list.is_empty() ? "true" : "false") << "\n";
  //  cout << " count " << (list.count()) << "\n";
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
  cout << "\n insert 5 at 2"
       << "\n";
  list.insert(2, 5);
  cout << " insert -10 at 0 "
       << "\n";
  list.insert(0, -10);
  cout << " insert 100 at 3 "
       << "\n";
  list.insert(3, 100);
  cout << " print list "
       << "\n";
  curr = list.get_front();
  while (curr) {
    cout << curr->data << "\t";
    curr = curr->next;
  }
  cout << " remove -10 "
       << "\n";
  list.remove(-10);
  cout << " remove 100"
       << "\n";
  list.remove(100);
  cout << " print list "
       << "\n";
  curr = list.get_front();
  while (curr) {
    cout << curr->data << "\t";
    curr = curr->next;
  }

  cout << "\n print reversed list "
       << "\n";
  list.reverse();

  curr = list.get_front();
  while (curr) {
    cout << curr->data << "\t";
    curr = curr->next;
  }
}