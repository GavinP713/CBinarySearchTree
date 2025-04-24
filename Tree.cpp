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
  cout << "remove(" << value << ")" << endl;
  // locate node
  Node* targetNode = search(value);

  //  if (targetNode == nullptr) return;
  
  // quick references for convenience
  Node* parent = targetNode->parent;
  Node* left = targetNode->left;
  Node* right = targetNode->right;
  cout<<"Parent: "<<parent<<endl;
  cout<<"Left: "<<left<<endl;
  cout<<"Right: "<<right<<endl;

  // both children
  if (left != nullptr && right != nullptr) {
    cout << " both children" << endl;
    Node* node = right;

    // search subtree for min
    cout << "  search subtree for min" << endl;
    while (node->left != nullptr) {
      node = node->left;
    }

    // replace
    int nodeValue = node->value;
    remove(nodeValue); // does another search loop (ineffecient)
    targetNode->value = nodeValue;
    cout << head->value << endl;
    if (targetNode == head) return;
  }
  // one left child
  else if (left != nullptr) {
    cout << " left child" << endl;
    // link child to parent
    if (parent->left == targetNode) parent->left = left;
    else parent->right = left;
  }
  // one right child
  else if (right != nullptr) {
    cout << " right child" << endl;
    // link child to parent
    if (parent->left == targetNode) parent->left = right;
    else parent->right = right;
  }
  // no children
  else {
    cout << " no children" << endl;
    cout<<"Parent: "<<parent<<endl;
    cout<<"Left: "<<left<<endl;
    cout<<"Right: "<<right<<endl;
    cout<<"Pain"<<targetNode<<endl;
    // unlink child to parent
    if (parent->left == targetNode) parent->left = nullptr;
    else parent->right = nullptr;
  }

  delete targetNode;
}

Node* Tree::search(int value) {
  cout << "search(" << value << ")" << endl;
  Node* node = head;

  // loop until value is found
  while (true) {
    cout << " node: " << node->value << endl;
    
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
      cout << "  go left" << endl;
      node = node->left;
    }
    // go right (value is higher)
    else if (value > node->value) {
      cout << "  go right" << endl;
      node = node->right;
    }
  }

  cout << "exit return" << endl;
  return nullptr;
}
