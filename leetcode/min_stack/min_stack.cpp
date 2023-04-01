//Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
//Implement the MinStack class:
//
//MinStack() initializes the stack object.
//void push(int val) pushes the element val onto the stack.
//void pop() removes the element on the top of the stack.
//int top() gets the top element of the stack.
//int getMin() retrieves the minimum element in the stack.
//You must implement a solution with O(1) time complexity for each function.

#include <iostream>
using namespace std;

template <typename T> struct Node {
public:
  T data;
  Node *next;
  Node(T data) { this->data = data; }
};

template <typename T> class Stack {
private:
  int size{0};
  Node<T> *head{nullptr};

public:
  Stack() {}
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
  int get_size() { return this->size; }
  void print() {
    Node<T> *curr = this->head;
    while (curr) {
      cout << curr->data << "\t";
      curr = curr->next;
    }
  }
};

class MinStack {
private:
  Stack<int> *numsStack;
  Stack<int> *minsStack;

public:
  MinStack() {
    this->numsStack = new Stack<int>();
    this->minsStack = new Stack<int>();
  }

  void push(int val) {
    this->numsStack->push(val);
    this->minsStack->push(this->minsStack->peek() &&
                                  this->minsStack->peek()->data < val
                              ? this->minsStack->peek()->data
                              : val);
  }

  void pop() {
    this->numsStack->pop();
    this->minsStack->pop();
  }

  int top() {
    return this->numsStack->peek() ? this->numsStack->peek()->data : -1;
  }

  int getMin() {
    return this->minsStack->peek() ? this->minsStack->peek()->data : -1;
  }
};

int main() {

  MinStack *minStack = new MinStack();

  cout << "min stack push [1,22,-3,4,-5,6] "
       << "\n";
  minStack->push(1);
  minStack->push(22);
  minStack->push(-3);
  minStack->push(4);
  minStack->push(-5);
  minStack->push(6);
  cout << "min stack pop " << minStack->top() << "\n";
  minStack->pop();
  cout << "min stack get min " << minStack->getMin() << "\n";
  cout << "min stack pop " << minStack->top() << "\n";
  minStack->pop();
  cout << "min stack get min " << minStack->getMin() << "\n";
  cout << "min stack pop " << minStack->top() << "\n";
  minStack->pop();
  cout << "min stack get min " << minStack->getMin() << "\n";
  cout << "min stack pop " << minStack->top() << "\n";
  minStack->pop();
  cout << "min stack get min " << minStack->getMin() << "\n";
  cout << "min stack pop " << minStack->top() << "\n";
  minStack->pop();
  cout << "min stack get min " << minStack->getMin() << "\n";
}