#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node (int value) {
        data = value;
        next = NULL;
    }
};

class LinkedListStack {
    private:
    Node* head = NULL;
    int size = 0;

    public:

    LinkedListStack() {
        head =  NULL;
        size = 0;
    }

    void push (int value) {
        Node* element = new Node(value);
        element -> next = head;
        head = element;
        size++;
    }

    int pop() {
        if (head == NULL) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int value = head -> data;
        Node* temp = head;
        head = head -> next;
        delete temp;
        size--;
        return value;
    }

    int top() {
        if (head == NULL) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return head -> data;
    }

    bool isEmpty() {
        return size == 0;
    }
};

int main() {
    LinkedListStack st;
    vector<string> commands = {"push", "push", "push", "top", "pop", "pop", "top", "push", "isEmpty" , "top"};
    vector<int>  values = {1, 2, 3, -1, -1, -1, -1, 4, -1, -1};
    for (int i = 0; i < commands.size(); i++) {
        if (commands[i] == "push") {
            cout << "push " << values[i] << endl;
            st.push(values[i]);
        }
        else if (commands[i] == "pop") {
            cout << "pop " << st.pop() << endl;
        }
        else if (commands[i] == "top") {
            cout << "top " << st.top() << endl;
        }
        else if (commands[i] == "isEmpty") {
            cout << "isEmpty " << (st.isEmpty() ? "true" : "false") << endl;
        }
    }
    return 0;
}