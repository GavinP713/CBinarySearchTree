#include "Tree.h"
#include "Node.h"
#include <iostream>
using namespace std;

Tree::Tree() {
  head = nullptr;
}

Tree::~Tree() {

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
  cout << "remove" << endl;
  // locate node
  Node* targetNode = search(value);

  // quick references for convenience
  Node* parent = targetNode->parent;
  Node* left = targetNode->left;
  Node* right = targetNode->right;

  // both children
  // !!!! problem !!!!! (LOTS of recursion, finds same value each recursion)
  //            only does this single if statment
  if (left != nullptr && right != nullptr) {
    cout << "both" << endl;
    Node* node = right;

    cout << "    - " << node->value;
    // search subtree for min
    while (node->left != nullptr) {
      cout << "    - " << node->value;
      node = node->left;
    }

    // replace
    targetNode->value = node->value;
    remove(node->value); // does another search loop which is ineffecient but im lazy
  }
  // one left child
  else if (left != nullptr) {
    cout << "left" << endl;
    // link child to parent
    if (parent->left == targetNode) parent->left = left;
    else parent->right = left;
  }
  // one right child
  else if (right != nullptr) {
    cout << "right" << endl;
    // link child to parent
    if (parent->left == targetNode) parent->left = right;
    else parent->right = right;
  }
  // no children
  else {
    cout << "none" << endl;
    // unlink child to parent
    if (parent->left == targetNode) parent->left = nullptr;
    else parent->right = nullptr;
  }

  delete targetNode;
  
  // Node* node = search(value);
  
  // if (node != nullptr) {
  //   delete node;
  // }
}

Node* Tree::search(int value) {
  cout << "search" << endl;
  Node* node = head;

  // loop until value is found
  while (node->value != value || node != nullptr) {
    // found
    if (value == node->value) {
      cout << "Found " << value << endl;
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
  cout << "Could not find value!" << endl;
  return nullptr;
}
