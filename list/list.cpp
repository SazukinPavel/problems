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
  ~List() {
    delete root;
    delete last;
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
    list.unshift(7);
    cout << " count " << list.count() << "\n";
    cout << " pop " << list.pop() << "\n";
    cout << " shift " << list.shift() << "\n";
    cout << " count " << list.count() << "\n";
    cout << " find 4 " << list.find(4) << "\n";
    cout << " find 666 " << list.find(666) << "\n";
    cout << "LIST TYPE STRING"
         << "\n";
    List<std::string> list2(10);
    cout << " is empty " << list2.is_empty() << "\n";
    list2.push("some 1");
    list2.push("some 2");
    list2.push("some 3");
    list2.push("some 4");
    list2.push("some 5");
    list2.push("some 6");
    list2.unshift("some 7");
    cout << " count " << list2.count() << "\n";
    cout << " pop " << list2.pop() << "\n";
    cout << " shift " << list2.shift() << "\n";
    cout << " count " << list2.count() << "\n";
    cout << " find some 4 " << list2.find("some 4") << "\n";
    cout << " find some666 " << list2.find("some666") << "\n";
  } catch (const char *error) {
    cout << "External execption: " << error << std::endl;
  }
}