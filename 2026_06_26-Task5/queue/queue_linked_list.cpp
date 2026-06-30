#include <iostream>
#include <string>

class Element {
  public:
    std::string value;
    Element *next;
    Element (std::string value) {
      this->value = value;
      next = nullptr;
    }
  
    void enqueue(Element *newElement) {
      next = newElement;
    }

    void dequeue(Element *&the_element) {
      if(!the_element) {
        std::cout<<"Queue underflow";
        return;
      }
      Element *temp = the_element;
      the_element = the_element->next;
      delete temp;
    }
};

int main() {
  Element *element1 = new Element("Appan");
  Element *element2 = new Element("Alfan");
  Element *element3 = new Element("Dzikra");
  Element *element4 = new Element("Saqib");
  Element *element5 = new Element("Wafi");

  element1->enqueue(element2);
  element2->enqueue(element3);
  element3->enqueue(element4);
  element4->enqueue(element5);
  element1->dequeue(element1);
  element1->dequeue(element1);

  Element *current = element1;
  while(current) {
    std::cout<<current->value<<" "<<std::endl;
    current = current->next;
  } 

  std::cin.get();
  return 0;
}