#include "Stack.h"
#include <iostream>
using namespace std;
#define el '\n'

void test(){
    Stack s1(5);
    s1.push(10);
    s1.push(20);
    s1.print();
    cout<<"--- Push Pop Top Size ---"<<el;
    cout<<"top element:"<<s1.top()<<el;
    cout<<"Current size:"<<s1.size()<<el;
    cout<<"Popped:"<<s1.pop()<<el;
    s1.print();
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.push(60);
    cout<<"Is Full?"<<(s1.isFull()?"Yes":"No")<<el;
    s1.print();
    cout<<"--- Deep Copy ---"<<el;
    Stack s2=s1;
    cout<<el;
    cout<<"After Deep Copy (s2=s1):"<<el;
    cout<<"s1:";
    s1.print();
    cout<<"s2:";
    s2.print();
    s1.pop();
    s1.push(999);
    cout<<el;
    cout<<"After modifying s1:"<<el;
    cout<<"s1 (Modified):";
    s1.print();
    cout<<"s2 (Unchanged):";
    s2.print();
    Stack s3(2);
    s3.push(1);
    s3.push(2);
    s3.print();
    cout<<el;
    cout<<"Copy Assignment (s3=s2):"<<el;
    s3=s2;
    cout<<"s2:";s2.print();
    cout<<"s3:";s3.print();
    cout<<el<<"Move via move():"<<el;
    s3.move(s1);
    cout<<"s3 (after move from s1):";
    s3.print();
    cout<<"s1 (after move):";
    s1.print();
}

int main(){
    test();
    return 0;
}
