#include <iostream>
template <typename T> struct Node {
public:
  T data;
  Node *next;
  Node(T data) { this->data = data; }
};