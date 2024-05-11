#include <stdio.h>
#include <math.h>

double Polynomial_Evoluation(int degree, float coefficients[], float x)
{
    float result = 0;
    for (int i = 0; i < degree; i++)
    {
        result += coefficients[i] * pow(x, i);
    }
    return result;
}

int main()
{
    int degree;
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);
    float coefficients[degree + 1];
    printf("Enter the coefficients of the polynomial starting from the constant term: \n");
    for (int i = 0; i < degree; i++)
    {
        printf("Coefficient for x^%d: ", i);
        scanf("%f", &coefficients[i]);
    }
    float x;
    printf("Enter the value of x for evaluation: ");
    scanf("%f", &x);
    float res = Polynomial_Evoluation(degree, coefficients, x);
    printf("Result of the polynomial evaluation for x = %.2f is: %.2f\n", x, res);
    return 0;
}