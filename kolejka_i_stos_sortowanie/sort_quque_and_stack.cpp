/**
Rozwiazanie dostepne takze pod adresem: https://github.com/piotrpasich/algorytmy/blob/master/kolejka_i_stos_sortowanie/sort_quque_and_stack.cpp
FIFO QUEUE: 

Input queue: 
0: 2
1: 5
2: 1
3: 7
4: 8
5: 0
6: 9
7: 3
8: 6
9: 4

Output queue: 
0: 1
1: 2
2: 3
3: 4
4: 5
5: 6
6: 7
7: 9

**/
#include <bits/stdc++.h> 
#include <iostream>
#include <cstdlib>
#include <string>
  
using namespace std; 
  
#define MAX 1000 

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
  
class Stack { 
  private:
    int sptr; 
  
    int a[MAX]; // Maximum size of Stack       
  public: 
    Stack() {
      sptr = -1;
    } 
    bool push(int x) { 
      if (sptr >= (MAX - 1)) { 
        cout << "Stack Overflow"; 
        return false; 
      } else { 
        a[++sptr] = x; 
        return true; 
      } 
    } 
    int pop() { 
      if (sptr < 0) { 
        cout << "Stack Underflow"; 
        return 0; 
      } else { 
        return a[sptr--]; 
      } 
    } 
    int top() { 
      if (sptr < 0) { 
        cout << "Stack is Empty"; 
        return 0; 
      } else { 
        return a[sptr]; 
      } 
    }  
    bool empty() {
      return (sptr < 0);
    }
    
    void Print() {
      cout << endl << "temp stack " << sptr;
      for(int i =0 ; i <= sptr;i++) {
        cout << endl << a[i];
      }
    }
}; 
  
class StackSort {
  private: 
    QueueFIFO* StackToQueue(Stack stack, QueueFIFO* queueFifo) {
      while (int top = stack.top()) {
        queueFifo->Push(top);
        stack.pop();
      }
      
      return queueFifo;
    }
  public: 
    QueueFIFO* Sort(QueueFIFO* queueFifo) {
      class Stack tempStack; 
      
      while (Node* node = queueFifo->Front()) {
        int tempElement = node->GetValue();
        while (!tempStack.empty() && (tempStack.top() < tempElement && tempStack.top() != 0)) {
          queueFifo->Push(tempStack.top());
          tempStack.pop();
        }

        tempStack.push(tempElement);
      }
      
      return StackToQueue(tempStack, queueFifo);
    }
    
 
};
// Driver program to test above functions 
int main() {
    cout << endl << "FIFO QUEUE: " << endl;
    QueueFIFO* queueFifo = new QueueFIFO();
    
    queueFifo->Push(2);
    queueFifo->Push(5);
    queueFifo->Push(1);
    queueFifo->Push(7);
    queueFifo->Push(8);
    queueFifo->Push(0);
    queueFifo->Push(9);
    queueFifo->Push(3);
    queueFifo->Push(6);
    queueFifo->Push(4);
  
    cout << endl << "Input queue: " << endl;
    queueFifo->Print();

    class StackSort stackSort;
    queueFifo = stackSort.Sort(queueFifo);
    
    cout << endl << "Output queue: " << endl;
    queueFifo->Print();    
 
    return 0; 
} 
