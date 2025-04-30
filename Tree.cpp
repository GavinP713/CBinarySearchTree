#include "Tree.h"
#include "Node.h"
#include <iostream>
using namespace std;

Tree::Tree() {
  head = nullptr;
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
  //  cout << "remove(" << value << ")" << endl;
  
  // locate node
  Node* targetNode = search(value);
  
  // quick references for convenience
  Node* parent = targetNode->parent;
  Node* left = targetNode->left;
  Node* right = targetNode->right;

  // both children
  if (left != nullptr && right != nullptr) {
    //    cout << " both children" << endl;
    Node* node = right;

    // search subtree for min
    //    cout << "  search subtree for min" << endl;
    while (node->left != nullptr) {
      node = node->left;
    }

    // replace
    int nodeValue = node->value;
    remove(nodeValue); // does another search loop (ineffecient)
    targetNode->value = nodeValue;

    // update parent
    
  }
  // one left child
  else if (left != nullptr) {
    //    cout << " left child" << endl;
    // link child to parent
    if (parent->left == targetNode) {
      parent->left = left;
      left->parent = parent;
    }
    else {
      parent->right = left;
      left->parent = parent;
    }
    delete targetNode;
  }
  // one right child
  else if (right != nullptr) {
    //cout << " right child" << endl;
    // link child to parent
    if (parent->left == targetNode) {
      parent->left = right;
      right->parent = parent;
    }
    else {
      parent->right = right;
      right->parent = parent;
    }
    delete targetNode;
  }
  // no children
  else {
    // unlink child to parent
    if (parent->left == targetNode) parent->left = nullptr;
    else parent->right = nullptr;
    delete targetNode;
  }
}

Node* Tree::search(int value) {
  //  cout << "search(" << value << ")" << endl;
  Node* node = head;

  // loop until value is found
  while (true) {
    // could not find (reached a leaf)
    if (node == nullptr) {
      cout << "Could not find value!" << endl;
      break;
    }
    // found
    else if (value == node->value) {
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

  cout << "exit return" << endl;
  return nullptr;
}
