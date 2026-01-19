#include <bits/stdc++.h>
using namespace std;

class StackQueue
{
private:
    stack<int> input;
    stack<int> output;

public:
    StackQueue() {}

    void push(int x)
    {
        input.push(x);
    }

    int pop()
    {
        if (output.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }
        if(output.empty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int value = output.top();
        output.pop();
        return value;
    }

    int peek()
    {
        if (output.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }
        if (output.empty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return output.top();
    }

    bool isEmpty()
    {
        return input.empty() && output.empty();
    }
};

int main()
{
    StackQueue q;
    vector<string> commands = {"isEmpty", "push", "push", "push", "pop", "peek", "pop", "peek", "isEmpty"};
    vector<int> values = {-1, 10, 20, 30, -1, -1, -1, -1, -1};
    for (int i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "push")
        {
            q.push(values[i]);
        }
        else if (commands[i] == "pop")
        {
            cout << q.pop() << endl;
        }
        else if (commands[i] == "peek")
        {
            cout << q.peek() << endl;
        }

        else if (commands[i] == "isEmpty")
        {
            cout << (q.isEmpty() ? "Empty" : "Not Empty") << endl;
        }
    }
    return 0;
}
