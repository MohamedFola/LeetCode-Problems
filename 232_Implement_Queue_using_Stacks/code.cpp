#include<iostream>
#include<stack>

class MyQueue {
private:
    std::stack<int> myStack1; // the main stack that represents our queue
    std::stack<int> myStack2; // temporaty stack used to do some processing before pushing a new element
public:

    std::stack<int> my_stack_R; // stack for reverse adding of elements

    MyQueue() {
    }
    
    void push(int x) {
        if(myStack1.empty())
            myStack1.push(x);
        else
        {
            while(!myStack1.empty())
            {
                myStack2.push(myStack1.top());
                myStack1.pop();
            }

            myStack2.push(x);

            while(!myStack2.empty())
            {
                myStack1.push(myStack2.top());
                myStack2.pop();
            }
        }
            
    }
    
    int pop() {
        int poped_element = myStack1.top();
        myStack1.pop();
        return poped_element;
    }
    
    int peek() {
        return myStack1.top();
    }
    
    bool empty() {
        return myStack1.empty();
    }
};

void print_queue(MyQueue& q)
{
    std::cout << "Elements of the queue: ";
    while(!q.empty())
    {
        std::cout << q.peek() << "  ";
        q.pop();
    }
    std::cout << "\n";
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main()
{
    MyQueue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    print_queue(q); // 1 2 3 4

    q.push(9);
    q.push(10);
    q.pop();
    q.push(5);
    q.push(3);
    q.pop();
    q.pop();

    print_queue(q); // 3

    return 0;
}