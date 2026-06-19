#include <iostream>
#include <string>

class Node {
  private:
    int index;
  public:
    std::string value;
    Node *next_node;
    Node(std::string value, int index) {
      this->value = value;
      this->index = index;
      next_node = nullptr;
    }
    auto getIndex() {
      return &next_node;
    }
};

int main() {
  Node *node1 = new Node("Ananda0", 1);
  node1->next_node = new Node("Ananda1", 2);
  node1->next_node->next_node = new Node("Ananda2", 3);
  node1->next_node->next_node->next_node = new Node("Ananda3", 4);
  Node *current = node1;
  // std::cout<<node1->value<<" "<<node1->getIndex()<<std::endl;
  // std::cout<<node1->next_node->value<<" "<<node1->next_node->getIndex()<<std::endl;
  for(int i=0;i<4;i++) {
    std::cout<<current->value<<std::endl;
    current = current->next_node;
  }
  std::cin.get();
  return 0;
}