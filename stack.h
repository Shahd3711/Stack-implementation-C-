#ifndef STACK_H
#define STACK_H
class Stack 
{
private:
    int* arr;
    int peak;
    int capacity;

public:
    Stack(int size);
    Stack();
    Stack(const Stack& other);
    ~Stack();
    Stack& operator=(const Stack& other);
    void push(int value);
    int pop();
    int top() const;
    bool isEmpty() const;
    bool isFull() const;
    int size() const;
    void print() const;
};
#endif