
#include <string>

using namespace std;

class Element {
    private:
        int value;
    public:
        Element (int value) {
            this->value = value;
        }
        
        int Value() {
            return value;
        }
};

class LinkedListElement {
    private:
        LinkedListElement* next;
        Element element;
        int length = 0;
    public:
        LinkedListElement (Element * el) {
            this->element = el;
        }

        Element * GetElement() {
            return this->element;
        }
        
        LinkedListElement * Next() {
            return next;
        }
        
        void SetNext(LinkedListElement * next) {
            this->next = next;
        }       
};

class LinkedList {
    private:
        LinkedListElement *head;
        LinkedListElement *tail;
    public:
        LinkedList () {
            head = null;
            tail = null;
        }
        // Push one element onto the end of the list
        bool Push (Element element) {
           LinkedListElement *listElement = new LinkedListElement(element);
           head = listElement;
           tail = listElement;
        }
        // Pop the element off the end of array
        bool Pop () {
        }
        // Shift an element off the beginning of list
        bool Shift () {
        }
        // Prepend one element to the beginning of a list
        bool Unshift (Element element) {
        }
        // Insert element onto selected place
        bool Insert(Element element, int index) {
        }
        // Remove element from selected index
        bool Remove(int index) {
        }
        
        void ToString() {
//            LinkedListElement *currentElement = firstElement;
//            do {
  //              printf("\n\n%d\n\n", firstElement->GetElement()->Value());
  //          } while(currentElement = firstElement->Next());            
        } 
};


int main() {
    Element* el = new Element(1);
    LinkedList* list = new LinkedList();

    //list->Push(el);
    //list->ToString();
    
    return 1;
}   

