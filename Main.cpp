#include "Tree.h"
#include <iostream>
using namespace std;

void printTree(Tree* tree, Node* node, int depth);

int main() {
  cout << nullptr << endl;
  cout << "creating tree" << endl;
  Tree* tree = new Tree();
  cout<< "inserting" << endl;
  tree->insert(5);
  tree->insert(2);
  tree->insert(7);
  tree->insert(1);
  tree->insert(12);

  cout << "printing" << endl;
  printTree(tree, tree->head, 0);
  cout << endl;

  cout << "removing 7" << endl;
  tree->remove(7);

  cout << "printing" << endl;
  printTree(tree, tree->head, 0);
  cout << endl;

  cout << "removing 5" << endl;
  tree->remove(5);
  cout << endl;
  
  cout << "printing" << endl;  
  printTree(tree, tree->head, 0);
  cout << endl;

  
  return 0;
}

void printTree(Tree* tree, Node* node, int depth) {
  if (node->left != nullptr) {
    printTree(tree, node->left, depth + 1);
  }

  for (int d = 0; d < depth; d++) {
    cout << '\t';
  }

  cout << node->value << endl;

  if (node->right != nullptr) {
    printTree(tree, node->right, depth + 1);
  }
}
