#include<iostream>
using namespace std;
int gcd(int num1, int num2)
{
    if(num2==0) return num1;
    else return gcd(num2, num1%num2);
}
int main()
{
    cout<<"The gcd of two numbers are "<<gcd(20, 18)<<endl;
}