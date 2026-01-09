#include<bits/stdc++.h>
using namespace std;

class QueueStack {
    private :
    queue<int> q;

    public:
    void push(int x){
        int size = q.size();
        q.push(x);
        for (int i = 0; i< size; i++){
            q.push(q.front());
            q.pop();
        }
    }

    int pop(){
        int x = q.front();
        q.pop();
        return x;
    }

    int peek(){
        return q.front();
    }

    bool isEmpty(){
        return q.empty();
    }
};

int main() {
    QueueStack st;
    
    // List of commands
    vector<string> commands = {"QueueStack", "push", "push", 
                               "pop", "top", "isEmpty"};
    // List of inputs
    vector<vector<int>> inputs = {{}, {4}, {8}, {}, {}, {}};

    for (int i = 0; i < commands.size(); ++i) {
        if (commands[i] == "push") {
            st.push(inputs[i][0]);
            cout << "null ";
        } else if (commands[i] == "pop") {
            cout << st.pop() << " ";
        } else if (commands[i] == "top") {
            cout << st.peek() << " ";
        } else if (commands[i] == "isEmpty") {
            cout << (st.isEmpty() ? "true" : "false") << " ";
        } else if (commands[i] == "QueueStack") {
            cout << "null ";
        }
    }

    return 0;
}