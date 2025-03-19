#ifndef NODE_H
#define NODE_H

class Node {
 public:
  Node(int value);
  ~Node();
  Node* parent;
  Node* left;
  Node* right;
  int value;
};

#endif
