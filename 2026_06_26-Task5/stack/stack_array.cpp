#include <iostream>
#include <string>
#include <vector>

class Element {
  private:
    std::string name;
  public:
    Element(std::string name) {
      this->name = name;
    }
    std::string getName() {
      return name;
    }
};

std::vector<Element*> Queue;

void push(std::string name) {
  Queue.push_back(new Element(name));
}

void pop() {
  Queue.pop_back();
}

int main() {

  push("Laptop");
  push("Computer");
  push("Book");
  push("Backpack");
  push("Tablet");
  pop();
  
  for(int i=0; i<Queue.size(); i++) {
    std::cout<<i+1<<" "<<Queue[i]->getName()<<std::endl;
  }

  std::cin.ignore();
  return 0;
}