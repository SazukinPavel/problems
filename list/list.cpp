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
  int count{0};
  int capacity{10};

  void init(int data) {
    root = new Node(data);
    last = root;
    count++;
  }

public:
  List(){};
  List(int capasity) { this->capacity = capasity; };
  void push(int data) {
    if (root == NULL) {
      init(data);
    } else {
      Node *tempNode = new Node(data);
      last->next = tempNode;
      last = tempNode;
      count++;
    }
  }
  int pop() {
    if (root == NULL) {
      throw ;
    }

    Node *curNode = root;
    while (curNode && curNode->next) {
      curNode = curNode->next;
    }

    last = curNode;
    last->next = NULL;
    return curNode->data;
  }
};

int main() {
  List list{20};
  list.push(1);
  list.push(2);
  list.push(3);
  list.push(4);
  list.push(5);
  list.push(6);
  cout << list.pop();
}