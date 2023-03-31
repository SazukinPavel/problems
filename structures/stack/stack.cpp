// STACK
#include "node.cpp"
#include <iostream>
#include <map>
#include <optional>
#include <string>

using namespace std;

template <typename T> class Stack {
private:
  int size{0};
  int capacity{10};
  Node<T> *head{nullptr};

public:
  Stack() {}
  Stack(int capacity) { this->capacity = capacity; }
  ~Stack() {
    cout << "stack destructor"
         << "\n";
    Node<T> *curr = head;
    while (curr) {
      Node<T> *next = curr->next;
      delete curr;
      curr = next;
    }
  }
  Node<T> *pop() {
    if (is_empty()) {
      return nullptr;
    }

    Node<T> *poped = this->head;

    this->head = this->head->next;
    this->size--;

    poped->next = nullptr;
    return poped;
  }
  void push(T data) {
    if (is_full()) {
      throw "Stack capacity full";
    }

    Node<T> *newNode = new Node(data);

    if (this->is_empty()) {
      this->head = newNode;
    } else {
      newNode->next = head;
      this->head = newNode;
    }
    size++;
  }
  Node<T> *peek() {
    if (this->is_empty()) {
      return nullptr;
    }

    return this->head;
  }
  bool is_empty() { return this->size == 0; }
  bool is_full() { return this->size == capacity; }
  int get_size() { return this->size; }
  void print() {
    Node<T> *curr = this->head;
    while (curr) {
      cout << curr->data << "\t";
      curr = curr->next;
    }
  }
};

int main() {
  Stack<string> *stack = new Stack<string>();
  stack->push("1");
  stack->push("2");
  stack->push("3");
  stack->push("4");
  stack->push("5");
  stack->push("6");

  cout << "stack<string> push [1,2,3,4,5,6] "
       << "\n";
  cout << "print stack"
       << "\n";
  stack->print();
  cout << "\nstack get_size " << stack->get_size() << "\n";
  cout << "stack is_empty " << (stack->is_empty() ? "true" : "false") << "\n";
  cout << "stack is_full " << (stack->is_full() ? "true" : "false") << "\n";
  cout << "stack peek " << stack->peek()->data << "\n";
  cout << "stack pop " << stack->pop()->data << "\n";
  cout << "stack pop " << stack->pop()->data << "\n";
  cout << "stack pop " << stack->pop()->data << "\n";
  cout << "print stack"
       << "\n";
  stack->print();
}