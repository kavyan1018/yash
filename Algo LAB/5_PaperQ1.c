#include <stdio.h>

double evaluatePolynomial(double coeff[], int n, double x, int *loopCount) 
{
    double result = coeff[0]; 
    *loopCount = 0; 

    for (int i = 1; i < n; i++) 
    {
        result = result * x + coeff[i];
        (*loopCount)++; 
    }
    return result;
}

int main() 
{
    
    double coeff[] = {3, 2, 4, 1};
    int n = sizeof(coeff) / sizeof(coeff[0]);
    double x = 2.0;
    int loopCount = 0;

    double result = evaluatePolynomial(coeff, n, x, &loopCount);

    printf("The value of the polynomial is: %.2f\n", result);
    printf("The loop executed %d times\n", loopCount);

    return 0;
}
