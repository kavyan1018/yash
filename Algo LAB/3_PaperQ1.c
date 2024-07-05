#include<stdio.h>

int main()
{
    int n = 10;

    int fib[n];
    int lopp_cont = 0;
    int addition_count = 0;
    int assignment_count = 0;


    // Initialize the first two Fibonacci numbers
    fib[0] = 0;
    fib[1] = 1;
    assignment_count += 2; // Two assignments above

    // Genrate Fibobacci series

    for (int i = 2; i < n; i++)
    {
        lopp_cont++;
        fib[i] = fib[i-1] + fib[i-2];
        addition_count++; // Addition operation
        assignment_count++; // Assignment operation
    }

    // Print the Fibovacci series

    printf("Fibonacci Series: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");

    // Print counts of operations
    printf("Loop count: %d\n", lopp_cont);
    printf("Addition count: %d\n", addition_count);
    printf("Assignment count: %d\n", assignment_count);

    return 0;
}