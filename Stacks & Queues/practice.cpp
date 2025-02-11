#include <iostream>
using namespace std;


class Stack{
    int size ;
    int *arr;
    int top;

    Stack(int size){
        this->size = size;
        this->top = -1;
        int *arr = new int[size];

    }

    void push(int x ){
        top++;
        arr[top] = x;
    }

    int pop(){
        int help = arr[top];
        top--;
        return help;
    }


};