#ifndef TREE_H
#define TREE_H

#include "Node.h"

class Tree {
 public:
  Tree();
  ~Tree();
  void insert(int value);
  void remove(int value);
  Node* search(int value);
  Node* head;
};

#endif
