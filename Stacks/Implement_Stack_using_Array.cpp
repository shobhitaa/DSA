#include <bits/stdc++.h>
using namespace std;

class ArrayStack {
    private:
    int* stackArray;
    int top;
    int capacity;

    public:
    //Constructor to initialize stack
    ArrayStack(int size = 100) {
        capacity = size;
        stackArray = new int[capacity];
        top = -1;
    }

    //Destructor
    ~ArrayStack() {
        delete[] stackArray;
    }

    void push(int x){
        if (top >= capacity - 1){
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        stackArray[top] = x;
    }

    int pop(){
        if (isEmpty()){
            cout << "Stack is empty" << endl;
            return -1;
        }
        return stackArray[top--];
    }

    int peek(){
        if (isEmpty()){
            cout << "Stack is empty" << endl;
            return -1; 
        }
        return stackArray[top];
    }

    bool isEmpty(){
        return (top == -1);
    }
};

int main() {
    ArrayStack stack;
    vector<string> commands = {"ArrayStack", "push", "push", "top", "pop", "isEmpty"};
    vector<vector<int>> inputs = {{}, {5}, {10}, {}, {}, {}};

    for (size_t i = 0; i < commands.size(); ++i) {
        if (commands[i] == "push") {
            stack.push(inputs[i][0]);
            cout << "null ";
        } else if (commands[i] == "pop") {
            cout << stack.pop() << " ";
        } else if (commands[i] == "top") {
            cout << stack.peek() << " ";
        } else if (commands[i] == "isEmpty") {
            cout << (stack.isEmpty() ? "true" : "false") << " ";
        } else if (commands[i] == "ArrayStack") {
            cout << "null ";
        }
    }

    return 0;
}