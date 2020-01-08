/**
Piotr Pasich

Lista jednokierunkowa
Opracuj w języku C++ zestaw funkcji pozwalających na operacje na liście jednokierunkowej:

Print - przegląd całej listy
Unshift - dodanie elementu na początek listy
Push - dodanie elementu na koniec listy
Insert (liczy od 0) - dodanie elementu na wskazaną pozycję listy
Shift - usunięcie elementu z początku listy
Pop - usunięcie elementu z końca listy

Przetestowane w funkcji main - przetestuj działanie na 6 elementowym zbiorze liczb całkowitych oraz zapisz cały program na platformie. 

**/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Node {
    private: 
        int value;
        Node* next;
    public:
        Node (int value_) {
            this->value = value_;
        }
        
        int GetValue() {
            return this->value;
        }
        
        void SetNext(Node* next) {
            this->next = next;
        }
        
        void RemoveNext() {
            this->next = NULL;
        }
        
        Node* GetNext() {
            return next;
        }
};

class List {
    private: 
        Node* head;
        Node* tail;
        
        void RefreshTail() {
            Node* currentNode = this->head;
            while (currentNode->GetNext() != NULL) {
                currentNode = currentNode->GetNext();
            }
            tail = currentNode;
        }
    public: 
        List () {
            head = NULL;
            tail = NULL;
        }
        // Push one element onto the end of the list
        void Push(int value) {
            Node* node = new Node(value);
            if (head == NULL) {
                head = node;
            } else {            
                tail->SetNext(node);
            }
            tail = node;
        }
        
        // Pop the element off the end of array
        void Pop () {
            if (head == NULL) {
                return;
            }
            Node* currentNode = head;
            while (currentNode->GetNext() != tail) {
                currentNode = currentNode->GetNext();
            }
            currentNode->RemoveNext();
            RefreshTail();
        }
        // Shift an element off the beginning of list
        void Shift () {
            if (head == tail) {
                head = NULL;
                tail = NULL;
            } else if (head != NULL) {
                head = head->GetNext();
            }                
        }
        // Prepend one element to the beginning of a list
        void Unshift (int value) {
            Node* node = new Node(value);
            node->SetNext(head);
            head = node;
            RefreshTail();
        }
        // Insert element onto selected place or onto the end of list
        void Insert(int value, int index) {
            if (index == 0) {
                return Unshift(value);
            }
            Node* currentNode = head;
            int i = 0;
            while(currentNode && i != index - 1 && currentNode->GetNext() != NULL) {
                currentNode = currentNode->GetNext();
                i++;
            }
            
            Node* node = new Node(value);
            if (currentNode != NULL) {
                node->SetNext(currentNode->GetNext());
                currentNode->SetNext(node);
            } else {
                head = node;
            }
            RefreshTail();
        }
        // Remove element from selected index
        void Remove(int index) {
            if (index == 0) {
                return Shift();
            }
            Node* currentNode = head;
            int i = 0;
            while(currentNode && i != index - 1 && currentNode->GetNext() != NULL) {
                currentNode = currentNode->GetNext();
                i++;
            }
            currentNode->SetNext(currentNode->GetNext()->GetNext());
        }
        
        void Print () {
            Node* currentNode = this->head;
            int i = 0;
            while(currentNode){
                std::cout << i << ": " << currentNode->GetValue() << std::endl;
                currentNode = currentNode->GetNext();
                i++;
            }
        }
};

int main() {
    List* list = new List();
    
    list->Push(1);
    list->Push(2);
    list->Push(3);
    list->Push(4);
    list->Push(5);
  
    list->Pop();
    list->Push(6);
    
    list->Shift();
    list->Unshift(9);
    
    list->Insert(11,3);
    list->Insert(11,0);
    list->Insert(12,3);
    
    list->Remove(0);
    list->Print();
    
    return 0;
}
