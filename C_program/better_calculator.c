#include <stdio.h>
#include <stdlib.h>

int main()
{
    double num1, num2;
    char operator;
    printf("Enter first number: ");
    scanf("%lf", &num1);
    printf("Enter second number: ");
    scanf("%lf", &num2);
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);

    if(operator == '+')
        printf("%f\n", num1 + num2);
    else if(operator == '-')
        printf("%f\n", num1 - num2);
    else if(operator == '*')
        printf("%f\n", num1 * num2);
    else if(operator == '/')
        printf("%f\n", num1 / num2);
    else 
        printf("Invalid operator\n");
}
