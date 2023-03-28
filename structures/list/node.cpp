#include <iostream>
template <typename T> struct Node {
public:
  T data;
  Node *next;
  Node(T data) { this->data = data; }
  bool operator==(const Node &node) const {
    return this->data == node->data; }
  bool operator!=(const Node *node) const { return this->data != node->data; }
};