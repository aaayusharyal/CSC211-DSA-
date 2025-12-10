#include<iostream>
using namespace std;
class stack
{
    int *arr;
    int top;
    int size;
    public:
    stack(int size)
    {
     this->size = size;
     arr=new int[size];
     top = -1;
    }

    void push(int element)
    {
        if(top==size-1)
        {
            cout<<"Stack overflow"<<endl;//o(n)
        }
        else {
            top++;
            arr[top] = element;
        }
    }
    void pop()
    {
        if(top>=0)
        {
            top--;
        }
        else
        cout<<"Stack Underflow"<<endl;
    }
    int peek()
    {
        if(top>=0 && top<size)
        {
            return arr[top];
        }
        else{
            cout<<"Empty Stack";
            return -1;
        }
    }
    bool isempty()
    {
        if(top==-1)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    stack s1(10);
    s1.push(20);
    s1.push(90);
    s1.pop();
   cout<<"The top element is "<<s1.peek()<<endl;
}