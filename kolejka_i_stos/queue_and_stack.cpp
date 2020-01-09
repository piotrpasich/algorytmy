/**
Piotr Pasich

Imlementacja kolejki i stosu
Napisz program implementujący przy pomocy listy jednokierunkowej  kolejkę oraz stos.

Wynik: 
FIFO QUEUE: 

0: 1
1: 2
2: 3
3: 4
4: 5
Front: 1
0: 2
1: 3
2: 4
3: 5
4: 1
Front: 2
Front: 3
Front: 4
Front: 5
Front: 1
Front: false
PRIORITY QUEUE: 

0: 1
1: 5
2: 2
3: 3
4: 4
Front: 4
0: 1
1: 5
2: 2
3: 3
4: 1
Front: 1
Front: 3
Front: 2
Front: true


STACK

0: 1
1: 2
2: 3
3: 4
4: 5
Top: 5
Top: 5
Top: 5
Top after pop: 4
0: 1
1: 2
2: 3
3: 4
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
        
        Node* GetHead () {
            return head;
        }
        
        Node* GetTail () {
            return tail;
        }
        
        int GetLength () {
            int length = 0;
            Node* currentNode = head;
            while (currentNode->GetNext() != NULL) {
                currentNode = currentNode->GetNext();
                length++;
            }
            
            return length;
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
                cout << i << ": " << currentNode->GetValue() << endl;
                currentNode = currentNode->GetNext();
                i++;
            }
        }
};

class Queue {
    protected: 
        List* list;
    public: 
        Queue () {
            list = new List();
        }
        bool Empty() {
            return list->GetLength() == 0;
        }
        void Push(int value) {
            list->Push(value);
        }
        void Pop() {
            list->Pop();
        }
        void Print() {
            list->Print();
        }
};

class QueueFIFO : public Queue {
    public:
        void Push(int value) {
            list->Push(value);
        }
        Node* Front() {
            Node* frontNode = list->GetHead();
            list->Shift();
            
            return frontNode;
        }
};

class QueuePriority : public Queue {
    public:
        void Push(int value, int priority) {
            list->Insert(value, priority);
        }
        Node* Front() {
            Node* frontNode = list->GetTail();
            list->Pop();
            
            return frontNode;
        }
};

class Stack : public Queue {
    public:
        void Push(int value) {
            list->Push(value);
        }
        Node* Top() {
            Node* frontNode = list->GetTail();
            
            return frontNode;
        }
        
};

int main() {
    cout << "FIFO QUEUE: " << endl << endl;
    QueueFIFO* queueFifo = new QueueFIFO();
    
    queueFifo->Push(1);
    queueFifo->Push(2);
    queueFifo->Push(3);
    queueFifo->Push(4);
    queueFifo->Push(5);
  
    queueFifo->Print();
    cout << "Front: " << queueFifo->Front()->GetValue() << endl;
    queueFifo->Push(1);
    queueFifo->Print();
    cout << "Front: " << queueFifo->Front()->GetValue() << endl;
    cout << "Front: " << queueFifo->Front()->GetValue() << endl;
    cout << "Front: " << queueFifo->Front()->GetValue() << endl;
    cout << "Front: " << queueFifo->Front()->GetValue() << endl;
    cout << "Front: " << queueFifo->Front()->GetValue() << endl;
    cout << "Front: " << boolalpha << !!queueFifo->Front() <<  endl;


    cout << "PRIORITY QUEUE: " << endl << endl;
    QueuePriority* queuePriority = new QueuePriority();
    
    queuePriority->Push(1,2);
    queuePriority->Push(2,3);
    queuePriority->Push(3,4);
    queuePriority->Push(4,5);
    queuePriority->Push(5,1);
  
    queuePriority->Print();
    cout << "Front: " << queuePriority->Front()->GetValue() << endl;
    queuePriority->Push(1,100);
    queuePriority->Print();
    cout << "Front: " << queuePriority->Front()->GetValue() << endl;
    cout << "Front: " << queuePriority->Front()->GetValue() << endl;
    cout << "Front: " << queuePriority->Front()->GetValue() << endl;
    cout << "Front: " << boolalpha << !!queuePriority->Front() <<  endl;

    cout << endl << endl << "STACK" << endl << endl;
    Stack* stack = new Stack();
    stack->Push(1);
    stack->Push(2);
    stack->Push(3);
    stack->Push(4);
    stack->Push(5);
    stack->Print();
    cout << "Top: " << stack->Top()->GetValue() << endl;
    cout << "Top: " << stack->Top()->GetValue() << endl;
    cout << "Top: " << stack->Top()->GetValue() << endl;
    stack->Pop();
    cout << "Top after pop: " << stack->Top()->GetValue() << endl;
    stack->Print();

    return 0;
}
