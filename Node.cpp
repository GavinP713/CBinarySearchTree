#include "Node.h"

Node::Node(int _value) {
  parent = nullptr;
  left = nullptr;
  right = nullptr;
  value = _value;
}

Node::~Node() {
  // both children
  if (left != nullptr && right != nullptr) {
    Node* node = right;

    // search subtree for min
    while (node->left != nullptr) {
      node = node->left;
    }

    // replace
    value = node->value;
    delete node;
  }
  // one left child
  else if (left != nullptr) {
    // link child to parent
    if (parent->left == this) parent->left = left;
    else parent->right = left;
  }
  // one right child
  else if (right != nullptr) {
    // link child to parent
    if (parent->left == this) parent->left = right;
    else parent->right = right;
  }
  // no children
  else {
    // unlink child to parent
    if (parent->left == this) parent->left = nullptr;
    else parent->right = nullptr;
  }
}
