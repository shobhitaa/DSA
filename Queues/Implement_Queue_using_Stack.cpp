#include <bits/stdc++.h>
using namespace std;

class StackQueue {
    private:
    stack<int> s1;
    stack<int> s2;

    public:
    StackQueue() {}

    void push(int x) {
        while (!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() {
        while (s1.empty()){
            cout << "Queue is empty." << endl;
            return -1;
        }
        int value = s1.top();
        s1.pop();
        return value;
    } 

    int peek() {
        if (s1.empty()){
            cout << "Queue is empty." << endl;
            return -1;
        }
        return s1.top();
    }

    bool isEmpty() {
        return s1.empty();
    }
};

int main () {
    StackQueue q;
    vector<string> commands = {"isEmpty","push", "push", "peek", "pop", "push", "isEmpty", "peek"};
    vector<int> values = {-1, 10, 20, -1, -1, 30, -1, -1};
    for (int i = 0; i < commands.size(); i++) {
        if (commands[i] == "push") {
            q.push(values[i]);
            cout << "Pushed " << values[i] << " to queue." << endl;
        } else if (commands[i] == "pop") {
            int poppedValue = q.pop();
            if (poppedValue != -1) {
                cout << "Popped " << poppedValue << " from queue." << endl;
            }
        } else if (commands[i] == "peek") {
            int frontValue = q.peek();
            if (frontValue != -1) {
                cout << "Front element is " << frontValue << "." << endl;
            }
        } else if (commands[i] == "isEmpty") {
            cout << "Queue is " << (q.isEmpty() ? "empty." : "not empty.") << endl;
        }
    }
    return 0;
}