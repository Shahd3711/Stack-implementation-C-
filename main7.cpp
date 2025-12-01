#include "Stack.h"
#include <iostream>
using namespace std;
#define el '\n'
void test() 
{
    Stack s1(5);
    s1.push(10);
    s1.push(20);
    s1.print();
    cout<<"--- Push Pop Top Size ---"<<el;
    cout<<"top element: "<<s1.top()<<el;//20
    cout<<"Current size: " <<s1.size()<<el;//2
    cout<<"Popped: " <<s1.pop()<<el;//20
    s1.print();
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.push(60); 
    cout<<"Is Full? "<<(s1.isFull()?"Yes":"No")<<el;// Yes
    s1.print();
    cout<<"--- Deep Copy ---"<<el;
    Stack s2=s1;
    cout<<el;
    cout<<"After Deep Copy (s2 = s1):"<<el;
    cout<<"s1: "; 
    s1.print();
    cout<<"s2: ";
    s2.print();
    //Yalla aho changing s1 to make sure s2 is a separate copy (Deep Copy)
    s1.pop();//remove 60
    s1.push(999);//add 999
    cout<<el;
    cout<<"After modifying s1:"<<el;
    cout<<"s1 (Modified): "; 
    s1.print();//999
    cout<<"s2 (Unchanged): "; 
    s2.print();//still has 60
    Stack s3(2);//capacity 2
    s3.push(1);
    s3.push(2);
    s3.print();
    cout<<el;
    cout<<"Testing Copy Assignment (s3 = s2):"<<el;
    s3=s2;
    cout<<"s2: ";
    s2.print();//(10, 30, 40, 50, 60) //(60, 50, 40, 30, 10)
    cout<<"s3: ";
    s3.print();//(10, 30, 40, 50, 60) //(60, 50, 40, 30, 10)
}

int main() 
{
    test();
    return 0;
}