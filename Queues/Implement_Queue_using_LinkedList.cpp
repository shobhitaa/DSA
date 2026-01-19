#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node (int val) {
        data = val;
        next = NULL;
    }
};

class LinkedListQueue {
    private:
    Node *front;
    Node* rear;
    int size;

    public:

    LinkedListQueue() {
        front = NULL;
        rear = NULL;
        size = 0;
    }

    void push(int x) {
        Node* element = new Node(x);
        if (front == NULL) {
            front = rear = element;
        }
        else {
            rear -> next = element;
            rear = element;
        }
        size++;
    }

    int pop() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int value = front -> data;
        Node* temp = front;
        front = front -> next;
        delete temp;
        if (front == NULL) {
            rear = NULL;
        }
        size--;
        return value;
    }

    int peek() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front -> data;
    }

    bool isEmpty() {
        return (size == 0);
    }

    ~LinkedListQueue() {
        while (front != NULL) {
            Node* temp = front;
            front = front -> next;
            delete temp;
        }
    }
};

int main() {
    LinkedListQueue q;
    q.push(10);
    q.push(20);
    cout << q.peek() << endl; // 10
    cout << q.pop() << endl;  // 10 
    q.push(30);
    cout << q.peek() << endl; // 20
    cout << (q.isEmpty() ? "Empty" : "Not Empty") << endl; // Not Empty
    cout << q.pop() << endl; // 20
    cout << q.pop() << endl; // 30
    cout << (q.isEmpty() ? "Empty" : "Not Empty") << endl; // Empty
    return 0;
}