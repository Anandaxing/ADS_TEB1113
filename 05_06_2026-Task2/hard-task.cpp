#include <iostream>
#include <vector>

class Node {
  public: 
    int data;
    Node *left, *right;
    Node(int x) {
      data = x;
      left = nullptr;
      right = nullptr;
    }
};

int CountNode(Node *root) {
  if(root == nullptr) return 0;
  return CountNode(root->left) + CountNode(root->right);
}

std::vector<std::vector<int>> Construct(Node *root) {
  std::vector<std::vector<int>> the_matrix;
  int vector_size = CountNode(root);
  for(int i=0;i<vector_size;i++) {
    the_matrix.push_back(std::vector<int>(vector_size, 0));
  }
  
}

int main() {
  Node *root = new Node(5);
  root->left = new Node(1);
  root->right = new Node(2);
  root->left->left = new Node(0);
  root->left->right = new Node(4);
  root->right->left = new Node(3);
  Construct(root);
  return 0;
}