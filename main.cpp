#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

using namespace std;

const int SIZE = 10;

class Queue {
    private:
        int arr[SIZE];
        int front;
        int rear;
        int size;

    public:
        Queue() {
            front = rear = -1;
            size = 0;
        }
        void enqueue(int element) {
            if(size == SIZE) {
                cout << "queue is at capacity." << endl;
            } if(front == -1) {
                front++;
            }
            rear++;
            arr[rear] = element;
            size++;
        }

        int dequeue() {
            if (front == -1 || front > rear) {
                cout << "Queue is empty" << endl;
                return -1;
            }
            int element = arr[front];
            front++;
            size--;
            
            return element;
        }

        int peek() {
            if (front == -1 || front > rear) {
                cout << "Cannot peek elements." << endl;
                return -1;
            }
            
            return arr[front];
        }
        
        // Checks if the queue is empty
        bool isEmpty() {
            return (front == -1 || front > rear);
        }
        
        // Returns the total number of elements present in the queue
        int getSize() {
            return size;
        }
};


int main() {
    char infix[] = "a+b*c-(d/e+f*g*h)";
    char postFixExp;
    if(!balanced(infix)) {
        cout << "Invalid expression" << endl;
    } else {
        infixToPostFix(infix);
    }
    infixToPostFix(infix);


    Queue q;

    q.enqueue(1); // Insert element 1 at rear
    q.enqueue(2); // Insert element 2 at rear
    q.enqueue(3); // Insert element 3 at rear
    cout << "Size of queue: " << q.getSize() << endl;      
    
    cout << "Front element: " << q.peek() << endl;        
    cout << "Removed element: " << q.dequeue() << endl; 
    
    cout << "Size of queue: " << q.getSize() << endl;      
    
    q.enqueue(4);  // Insert element 4 at rear
    cout << "Front element: " << q.peek() << endl;        
    
    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
    
}
