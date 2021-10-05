// A program to print all perfect numbers between 1 to n.
// Perfect number is a positive integer which is equal to the sum of its proper positive divisors.
// Tue, Oct 5 2021

#include <stdio.h>

int getSumOfFactors(int n)
{
    // find all the factors and return the sum
    int sum = 0;

    for (int i = 1; i < n; i++)
        if (n % i == 0)
            sum += i;

    return sum;
}

int main()
{
    int n;

    // input the upper bound
    printf("\nEnter n: ");
    scanf("%d", &n);

    // iterate n times
    for (int i = 1; i <= n; i++)
        // check if i is a perfect number or not
        if (i == getSumOfFactors(i))
            printf("%d is a perfect number.\n", i);

    return 0;
}

/*
O/P

atharva-cm@ShadyXV:~/dev/campus-connect-bluepineapple/assignment_1$ ./a.out 

Enter n: 100
6 is a perfect number.
28 is a perfect number
*/