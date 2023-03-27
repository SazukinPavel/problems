// LIST
#include "node.cpp"
#include <iostream>
#include <map>
#include <string>
using std::cout;

template <typename T> class List {
private:
  Node<T> *root;
  Node<T> *last;
  int nodesCount{0};
  int capacity{10};

  void init(T data) {
    root = new Node(data);
    last = root;
    nodesCount++;
  }

public:
  List() {
    root = nullptr;
    last = nullptr;
  };
  List(int capasity) {
    this->capacity = capasity;
    root = nullptr;
    last = nullptr;
  };
  int count() { return this->nodesCount; }
  Node<T> *getRoot() { return root; };
  void push(T data) {
    if (this->count() > capacity) {
      throw "Capacity error";
    }

    if (is_empty()) {
      init(data);
    } else {
      Node<T> *tempNode = new Node(data);
      last->next = tempNode;
      last = tempNode;
      nodesCount++;
    }
  }
  T pop() {
    if (is_empty()) {
      throw "List is empty!";
    }

    if (last == root) {
      return shift();
    }

    Node<T> *curNode = root;
    while (curNode->next != last)
      curNode = curNode->next;

    T data = last->data;
    delete last;
    last = curNode;
    last->next = nullptr;
    nodesCount--;

    return data;
  };
  T shift() {
    if (is_empty()) {
      throw "List is empty!";
    }

    T data = root->data;

    Node<T> *temp = root;
    root = temp->next;
    delete temp;
    nodesCount--;

    return data;
  };
  void unshift(T data) {
    if (this->count() > capacity) {
      throw "Capacity error";
    }

    if (is_empty()) {
      init(data);
    } else {
      Node<T> *newNode = new Node(data);
      newNode->next = root;
      root = newNode;
      nodesCount++;
    }
  }
  bool find(T data) {
    Node<T> *curNode = root;
    while (curNode != last) {
      if (data == curNode->data) {
        return true;
      }
      curNode = curNode->next;
    }
    return false;
  }
  bool is_empty() { return root == nullptr; };
  void reverse() {
    if (root != nullptr) {
      Node<T> *prevNode = root;
      Node<T> *curNode = root->next;

      prevNode->next = nullptr;

      while (curNode != nullptr) {
        Node<T> *tempNode = curNode->next;
        curNode->next = prevNode;
        prevNode = curNode;
        curNode = tempNode;
      }

      root = prevNode;
    }
  }
  Node<T> *operator[](int index) {
    Node<T> *curr=root;
    while(index!=0){
      if(curr==nullptr){
        return nullptr;
      }
      curr=curr->next;
      index--;
    }
    return curr;
  }
};

int main() {
  try {
    cout << "LIST TYPE INTEGER"
         << "\n";
    List<int> list(10);
    cout << " is empty " << list.is_empty() << "\n";
    list.push(1);
    list.push(2);
    list.push(3);
    list.push(4);
    list.push(5);
    list.push(6);
    cout << " list[4] " << list[4]->data << "\n";
    cout << " list[10] " << list[10] << "\n";
    cout << " list[1] " << list[1]->data << "\n";
  } catch (const char *error) {
    cout << "External execption: " << error << std::endl;
  }
}