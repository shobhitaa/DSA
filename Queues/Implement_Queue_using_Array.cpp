#include <bits/stdc++.h>
using namespace std;

class ArrayQueue {
    private:
    int* queueArray;
    int front;
    int rear;
    int capacity;
    int currentSize;

    public:
    //Constructor to initialize queue
    ArrayQueue(int size = 100) {
        capacity = size;
        currentSize = 0;
        queueArray = new int[capacity];
        front = -1;
        rear = -1;
    }

    //Destructor
    ~ArrayQueue() {
        delete[] queueArray;
    }

    void push(int x){
        if (currentSize >= capacity){
            cout << "Queue Overflow" << endl;
            return;
        }
        if (isEmpty()){
            front = 0;
            rear = 0;
        } else{
            rear = (rear + 1) % capacity;
        }
        queueArray[rear] = x;
        currentSize++;
    }

    int pop(){
        if (isEmpty()){
            cout << "Queue is empty" << endl;
            return -1;
        }
        int value = queueArray[front];
        if (currentSize == 1){
            front = -1;
            rear = -1;
        } else{
            front = (front + 1) % capacity;
        }
        currentSize--;
        return value;
    }

    int peek(){
        if (isEmpty()){
            cout << "Queue is empty" << endl;
            return -1; 
        }
        return queueArray[front];
    }

    bool isEmpty(){
        return (currentSize == 0);
    }
};

int main() {
    ArrayQueue queue;
    vector<string> commands = {"ArrayQueue", "push", "push", 
                               "peek", "pop", "isEmpty"};
    vector<vector<int>> inputs = {{}, {5}, {10}, {}, {}, {}};

    for (int i = 0; i < commands.size(); ++i) {
        if (commands[i] == "push") {
            queue.push(inputs[i][0]);
            cout << "null ";
        } else if (commands[i] == "pop") {
            cout << queue.pop() << " ";
        } else if (commands[i] == "peek") {
            cout << queue.peek() << " ";
        } else if (commands[i] == "isEmpty") {
            cout << (queue.isEmpty() ? "true" : "false") << " ";
        } else if (commands[i] == "ArrayQueue") {
            cout << "null ";
        }
    }

    return 0;
}