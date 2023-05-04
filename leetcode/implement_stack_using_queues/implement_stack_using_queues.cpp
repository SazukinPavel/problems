// Implement a last-in-first-out (LIFO) stack using only two queues.
// The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

// Implement the MyStack class:

// void push(int x) Pushes element x to the top of the stack.
// int pop() Removes the element on the top of the stack and returns it.
// int top() Returns the element on the top of the stack.
// boolean empty() Returns true if the stack is empty, false otherwise.
// Notes:

// You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
// Depending on your language, the queue may not be supported natively.
// You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.

#include "queue";
using namespace std;

class MyStack
{
private:
    queue<int> q;

public:
    void push(int x)
    {
        q.push(x);
        for (size_t i = 0; i < q.size() - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        int val = q.front();
        q.pop();
        return val;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};

int main()
{
    MyStack *obj = new MyStack();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->push(4);
    int param_2 = obj->pop();
    int param_3 = obj->top();
    bool param_4 = obj->empty();
}