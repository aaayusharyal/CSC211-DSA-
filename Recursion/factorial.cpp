#include<iostream>
using namespace std;
long int factorial(int num)
{
    if(num==0||num==1)
    return 1;
    else
    return (num*factorial(num-1));
}
int main()
{
    cout<<"The factorial of the number is"<<factorial(5);
}