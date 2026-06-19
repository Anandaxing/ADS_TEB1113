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
  return CountNode(root->left) + CountNode(root->right) + 1;
}

void FindAnc(Node *root, std::vector<int> anc, std::vector<std::vector<int>> &the_matrix) {
  if(root == nullptr) {
    return;
  }
  for(int i=0;i<anc.size();i++) {
    the_matrix[anc[i]][root->data] = 1;
  }
  anc.push_back(root->data);
  FindAnc(root->left, anc, the_matrix);
  FindAnc(root->right, anc, the_matrix);
}

std::vector<std::vector<int>> Construct(Node *root) {
  std::vector<std::vector<int>> the_matrix;
  std::vector<int> anc;
  int vector_size = CountNode(root);
  for(int i=0;i<vector_size;i++) {
    the_matrix.push_back(std::vector<int>(vector_size, 0));
  }
  FindAnc(root, anc, the_matrix);
  return the_matrix;
}

void Print(std::vector<std::vector<int>> the_v) {
  for(int i=0;i<the_v.size();i++) {
    for(int j=0;j<the_v[i].size();j++) {
      std::cout<<the_v[i][j]<<" ";
    }
    std::cout<<std::endl;
  }
}

int main() {
  Node *root = new Node(5);
  root->left = new Node(1);
  root->right = new Node(2);
  root->left->left = new Node(0);
  root->left->right = new Node(4);
  root->right->left = new Node(3);
  // Node *root = new Node(0);
  // root->left = new Node(1);
  // root->right = new Node(2);
  std::vector<std::vector<int>> the_vector = Construct(root);
  Print(the_vector);
  return 0;
}