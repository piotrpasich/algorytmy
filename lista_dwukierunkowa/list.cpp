/**
Piotr Pasich

Lista dwukierunkowa
Opracuj w języku C++ zestaw funkcji pozwalających na operacje na liście dwukierunkowej:

przegląd całej listy
dodanie elementu na początek listy
dodanie elementu na koniec listy
dodanie elementu na wskazaną pozycję listy
usunięcie elementu z początku listy
usunięcie elementu z końca listy
przetestuj działanie na 6 elementowym zbiorze liczb całkowitych oraz zapisz cały program na platformie.

From Head: 
0: 11
1: 9
2: 2
3: 12
4: 11
5: 4
6: 6
From Tail: 
0: 6
1: 4
2: 11
3: 12
4: 2
5: 9
6: 11


**/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Node {
    private: 
        int value;
        Node* next;
        Node* previous;
    public:
        Node (int value_) {
            this->value = value_;
        }
        
        int GetValue() {
            return value;
        }
        
        void SetNext(Node* next) {
            this->next = next;
        }
        
        void SetPrevious(Node* previous) {
            this->previous = previous;
        }
        
        void RemoveNext() {
            next = NULL;
        }
        
        void RemovePrevious() {
            previous = NULL;
        }
        
        Node* GetNext() {
            return next;
        }
        
        Node* GetPrevious () {
            return previous;
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
                node->SetPrevious(tail);
                tail->SetNext(node);
            }
            tail = node;
        }
        
        // Pop the element off the end of array
        void Pop () {
            if (head == NULL) {
                return;
            }
            if (tail == head) {
                head = tail;
                return;
            }
            tail->GetPrevious()->RemoveNext();
            RefreshTail();
        }
        // Shift an element off the beginning of list
        void Shift () {
            if (head == tail) {
                head = NULL;
                tail = NULL;
            } else if (head != NULL) {
                head = head->GetNext();
                head->RemovePrevious();
            }                
        }
        // Prepend one element to the beginning of a list
        void Unshift (int value) {
            Node* node = new Node(value);
            head->SetPrevious(node);
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
                currentNode->GetNext()->SetPrevious(node);
                node->SetNext(currentNode->GetNext());
                currentNode->SetNext(node);
                node->SetPrevious(currentNode);
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
            currentNode->GetNext()->SetPrevious(currentNode);
        }
        
        void Print () {        
            //from head
            std::cout << "From Head: " << endl;
            Node* currentNode = this->head;
            int i = 0;
            while(currentNode){
                cout << i << ": " << currentNode->GetValue() << endl;
                currentNode = currentNode->GetNext();
                i++;
            }
            
            //from tail
            std::cout << "From Tail: " << endl;
            currentNode = this->tail;
            i = 0;
            while(currentNode){
                cout << i << ": " << currentNode->GetValue() << endl;
                currentNode = currentNode->GetPrevious();
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

    list->Remove(4);
    list->Print();
    
    return 0;
}
