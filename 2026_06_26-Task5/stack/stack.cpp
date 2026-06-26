#include <iostream>
#include <string>

class Stack {
  public:
    std::string name;
    Stack *next;
    Stack(std::string name) {
      this->name = name;
      next = nullptr;
    }

    // push method
    Stack *push(Stack *newNode, Stack *current) {
      newNode->next = current;
      return newNode;
    }
    
    // pop method
    Stack *pop(Stack *currentNode) {
      currentNode = currentNode->next;
      return currentNode;
    }

    // peek method

};

int main() {
  Stack *node1 = new Stack("Ananda0");
  Stack *node2 = new Stack("Ananda1");
  Stack *node3 = new Stack("Ananda2");
  Stack *node4 = new Stack("Ananda3");

  node1 = node1->push(node2, node1);
  node1 = node1->push(node3, node1);
  node1 = node1->pop(node1);


  Stack *current = node1;

  for(int i=0;i<3;i++) {
    std::cout<<current->name<<std::endl;
    current = current->next;
  }
  std::cin.get();
  return 0;
}