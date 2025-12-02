#include "Stack.h"
#include <iostream>
#include <stdexcept>
using namespace std;
#define el "\n"

Stack::Stack(int size):capacity(size),peak(-1){
    if(size<=0) throw invalid_argument("Stack capacity must be positive.");
    arr=new int[capacity];
    cout<<"Stack created with capacity:"<<capacity<<el;
}

Stack::Stack():Stack(10){}

Stack::Stack(const Stack& other):capacity(other.capacity),peak(other.peak){
    arr=new int[capacity];
    for(int i=0;i<=peak;i++) arr[i]=other.arr[i];
    cout<<"Deep Copy Constructor executed."<<el;
}

Stack::~Stack(){
    delete[] arr;
    arr=nullptr;
    cout<<"Stack destroyed and memory freed."<<el;
}

Stack& Stack::operator=(const Stack& other){
    if(this!=&other){
        delete[] arr;
        capacity=other.capacity;
        peak=other.peak;
        arr=new int[capacity];
        for(int i=0;i<=peak;i++) arr[i]=other.arr[i];
    }
    cout<<"Deep Copy Assignment Operator executed."<<el;
    return *this;
}

void Stack::move(Stack& other){
    delete[] arr;
    arr=other.arr;
    capacity=other.capacity;
    peak=other.peak;
    other.arr=nullptr;
    other.capacity=0;
    other.peak=-1;
    cout<<"Move executed via move()"<<el;
}

void Stack::push(int value){
    if(isFull()) throw runtime_error("Stack Overflow: stack is full!");
    peak++;
    arr[peak]=value;
    cout<<"Pushed:"<<value<<el;
}

int Stack::pop(){
    if(isEmpty()) throw runtime_error("Stack Underflow: stack is empty!");
    return arr[peak--];
}

int Stack::top() const{
    if(isEmpty()) throw runtime_error("Stack is empty, cannot view top element.");
    return arr[peak];
}

bool Stack::isEmpty() const{return peak==-1;}
bool Stack::isFull() const{return peak==capacity-1;}
int Stack::size() const{return peak+1;}

void Stack::print() const{
    if(isEmpty()){cout<<"Stack is empty"<<el;return;}
    cout<<"Stack(peak->Bottom): ";
    for(int i=peak;i>=0;i--) cout<<arr[i]<<" ";
    cout<<el;
    cout<<"Stack(Bottom->peak): ";
    for(int i=0;i<=peak;i++) cout<<arr[i]<<" ";
    cout<<el;
}
