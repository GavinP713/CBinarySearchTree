#include "Tree.h"
#include "Node.h"
#include <iostream>
using namespace std;

Tree::Tree() {
  head = nullptr;
}

Tree::~Tree() {
  while (head != nullptr) {
    delete head;
  }
}

void Tree::insert(int value) {
  // insert head
  if (head == nullptr) {
    head = new Node(value, nullptr);
  }
  // insert leaf
  else {
    Node* current = head;
    
    // loop until leaf is found
    while (current != nullptr) {
      // go left
      if (value < current->value) {
	// insert (reached a leaf)
	if (current->left == nullptr) {
	  current->left = new Node(value, current);
	  return;
	}
	// continue
	else {
	  current = current->left;
	}
      }
      // go right
      else {
	// insert (reached a leaf)
	if (current->right == nullptr) {
	  current->right = new Node(value, current);
	  return;
	}
	// continue
	else {
	  current = current->right;
	}
      }
    }
  }
}

void Tree::remove(int value) {
  Node* node = search(value);
  
  if (node != nullptr) {
    delete node;
  }
}

Node* Tree::search(int value) {
  Node* node = head;

  // loop until value is found
  while (node->value != value || node != nullptr) {
    // found
    if (value == node->value) {
      return node;
    }
    // go left (value is lower)
    else if (value < node->value) {
      node = node->left;
    }
    // go right (value is higher)
    else if (value > node->value) {
      node = node->right;
    }
  }

  // if not found return null (doesnt exist)
  return nullptr;
}
