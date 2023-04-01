// STACK
#include "node.cpp"
#include <iostream>
#include <map>
#include <optional>
#include <string>

using namespace std;

template <typename T> class Queue {
private:
  int size{0};
  int capacity{10};
  Node<T> *head{nullptr};
  Node<T> *tail{nullptr};

public:
  Queue() {}
  Queue(int capacity) { this->capacity = capacity; }
  void enqueue(T data) {
    if (this->is_full()) {
      throw "Queue capacity error";
    }

    Node<T> *newNode = new Node<T>(data);
    if (this->head == nullptr) {
      this->head = newNode;
      this->tail = newNode;
    } else {
      this->tail->next = newNode;
      this->tail = newNode;
    }
    this->size++;
  }

  T dequeue() {
    if (!this->head) {
      throw "Try to dequeue empty queue";
    }

    T data = this->head->data;
    this->head = this->head->next;
    size--;

    return data;
  }

  T peek() {
    if (!this->head) {
      throw "Try to peek empty queue";
    }
    return this->head->data;
  }

  bool is_full() { return capacity == this->get_size(); }
  bool is_empty() { return this->get_size() == 0; }
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
  Queue<int> *queue = new Queue<int>();
  queue->enqueue(1);
  queue->enqueue(2);
  queue->enqueue(3);
  queue->enqueue(4);
  queue->enqueue(5);
  queue->enqueue(6);

  cout << "queue<int> enqueue [1,2,3,4,5,6] "
       << "\n";
  cout << "print queue"
       << "\n";
  queue->print();
  cout << "\n queue get_size " << queue->get_size() << "\n";
  cout << "queue is_empty " << (queue->is_empty() ? "true" : "false") << "\n";
  cout << "queue is_full " << (queue->is_full() ? "true" : "false") << "\n";
  cout << "queue peek " << queue->peek() << "\n";
  cout << "queue pop " << queue->dequeue() << "\n";
  cout << "queue pop " << queue->dequeue() << "\n";
  cout << "queue pop " << queue->dequeue() << "\n";
  cout << "queue pop " << queue->dequeue() << "\n";
  cout << "queue pop " << queue->dequeue() << "\n";
  cout << "queue pop " << queue->dequeue() << "\n";
  cout << "queue is_empty " << (queue->is_empty() ? "true" : "false") << "\n";
  cout << "queue is_full " << (queue->is_full() ? "true" : "false") << "\n";
  cout << "print queue"
       << "\n";
  queue->print();
}