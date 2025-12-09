#include <iostream>
using namespace std;
int reverseNumber(int n, int rev)
{
    if (n == 0)
        return rev;

    return reverseNumber(n / 10, rev * 10 + n % 10);
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    int reversed = reverseNumber(num, 0);

    if (num == reversed)
        cout << "Palindrome number";
    else
        cout << "Not a palindrome number";

    return 0;
}
