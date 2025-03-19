#include "Node.h"

Node::Node(int _value) {
  parent = nullptr;
  left = nullptr;
  right = nullptr;
  value = _value;
}

Node::~Node() {
  // remove link to parent
  if (parent->left == this) {
    parent->left = nullptr;
  }
  else if (parent->right == this) {
    parent->right = nullptr;
  }

  // link children to parent

  // wip:
  // both children
  if (parent->left != nullptr && parent->left != nullptr) {
    
  }
  // one left child
  else if (parent->left != nullptr) {

  }
  // one right child
  else if (parent->right != nullptr) {

  }
}
