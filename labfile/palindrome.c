#include <stdio.h>

int rev = 0;

/* Recursive function to reverse number */
void reverse(int n)
{
    if (n == 0)
        return;

    rev = rev * 10 + (n % 10);
    reverse(n / 10);
}

int main()
{
    int num, temp;

    printf("Enter a number: ");
    scanf("%d", &num);

    temp = num;
    reverse(num);

    if (rev == temp)
        printf("Palindrome number\n");
    else
        printf("Not a palindrome number\n");

    return 0;
}
