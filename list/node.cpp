#include <sys/types.h>

struct Node {
public:
  int data;
  ushort count{0};
  Node *next;
  Node(int data) { this->data = data; }

  void setNext(Node *next) { this->next = next; }
};