// LIST
#include "node.cpp"
#include <iostream>
#include <map>
#include <string>
using std::cout;

class List {
private:
  Node *root;
  Node *last;
  int nodesCount{0};
  int capacity{10};

  void init(int data) {
    root = new Node(data);
    last = root;
    nodesCount++;
  }

public:
  List(){};
  List(int capasity) { this->capacity = capasity; };
  int count() { return this->nodesCount; }
  Node *getRoot() { return root; };
  void push(int data) {
    if (this->count() > capacity) {
      throw "Capacity error";
    }

    if (is_empty()) {
      init(data);
    } else {
      Node *tempNode = new Node(data);
      last->next = tempNode;
      last = tempNode;
      nodesCount++;
    }
  }
  int pop() {
    if (is_empty()) {
      throw "List is empty!";
    }

    if (last == root) {
      return shift();
    }

    Node *curNode = root;
    while (curNode->next != last)
      curNode = curNode->next;

    int data = last->data;
    delete last;
    last = curNode;
    last->next = nullptr;
    nodesCount--;

    return data;
  };
  int shift() {
    if (is_empty()) {
      throw "List is empty!";
    }

    int data = root->data;

    Node *temp = root;
    root = temp->next;
    delete temp;
    nodesCount--;

    return data;
  };
  void unshift(int data) {
    if (this->count() > capacity) {
      throw "Capacity error";
    }

    if (is_empty()) {
      init(data);
    } else {
      Node *newNode = new Node(data);
      newNode->next = root;
      root = newNode;
      nodesCount++;
    }
  }
  bool find(int data) {
    Node *curNode = root;
    while (curNode != last) {
      if (data == curNode->data) {
        return true;
      }
      curNode = curNode->next;
    }
    return false;
  }
  bool is_empty() { return root == nullptr; };
};

int main() {
  try {
    List *list = new List(10);
    cout << " is empty " << list->is_empty() << "\n";
    list->push(1);
    list->push(2);
    list->push(3);
    list->push(4);
    list->push(5);
    list->push(6);
    list->unshift(7);
    cout << " count " << list->count() << "\n";
    cout << " pop " << list->pop() << "\n";
    cout << " shift " << list->shift() << "\n";
    cout << " count " << list->count() << "\n";
    cout << " find 4 " << list->find(4) << "\n";
    cout << " find 666 " << list->find(666) << "\n";
  } catch (const char *error) {
    cout << "External execption: " << error << std::endl;
  }
}