#include<iostream>
using namespace std;
int fibo(int num)
{
    if (num==1) return 0;
    if (num==2) return 1;
    else return fibo(num-1)+fibo(num-2);
}
int main()
{
cout<<"The value of nth fibonacci number is "<<fibo(9)<<endl;
return 0;
}