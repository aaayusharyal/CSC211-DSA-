#include <stdio.h>

/* Recursive function to reverse number */
void reverse(int n)
{
    if (n == 0)
        return;

    printf("%d", n % 10);   // print last digit
    reverse(n / 10);        // recursive call
}

int main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Reversed number: ");
    reverse(num);

    return 0;
}
