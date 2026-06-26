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

void enqueue(std::string name) {
  Queue.push_back(new Element(name));
}

void dequeue() {
  Queue.erase(Queue.begin());
}

int main() {

  enqueue("Laptop");
  enqueue("Computer");
  enqueue("Book");
  enqueue("Backpack");
  enqueue("Tablet");
  dequeue();
  
  for(int i=0; i<Queue.size(); i++) {
    std::cout<<i+1<<" "<<Queue[i]->getName()<<std::endl;
  }

  std::cin.ignore();
  return 0;
}