template <typename T> struct Node {
public:
  T data;
  Node *next;
  Node *prev;
  Node(T data) { this->data = data; }
};