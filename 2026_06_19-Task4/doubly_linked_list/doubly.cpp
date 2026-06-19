#include <iostream>
#include <string>

class Node {
  public:
    std::string value;
    Node *next_node;
    Node *prev_node;
    Node(std::string value) {
      this->value = value;
      next_node = nullptr;
      prev_node = nullptr;
    }
    auto getIndex() {
      return &next_node;
    }
};

int main() {
  Node *node1 = new Node("Ananda2");
  Node *node2 = new Node("Ananda3");
  Node *node3 = new Node("Ananda4");
  Node *node4 = new Node("Ananda5");
  Node *current = node1;
  node1->next_node = node2;

  node2->next_node = node3;
  node2->prev_node = node1;

  node3->next_node = node4;
  node3->prev_node = node2;

  node4->next_node = node1;
  // std::cout<<node1->value<<" "<<node1->getIndex()<<std::endl;
  // std::cout<<node1->next_node->value<<" "<<node1->next_node->getIndex()<<std::endl;
  for(int i=0;i<4;i++) {
    std::cout<<current->value<<std::endl;
    current = current->next_node;
  }
  std::cin.get();
  return 0;
}