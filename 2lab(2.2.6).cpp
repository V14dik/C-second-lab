#include <stdio.h>
#include <conio.h>
#include <math.h>
#define _USE_MATH_DEFINES
#include<cmath>

int main(void)
{
    float eps;
    printf("Enter epsilon: ");
    while (scanf_s("%f", &eps) != 1 || eps >= 1 || eps <= 0)
    {
        rewind(stdin);
        printf("Bad input.\nEnter epsilon: ");
    }

    int angle;//в градусах
    printf("Enter angle in degerees: ");
    while (scanf_s("%d", &angle) != 1)
    {
        rewind(stdin);
        printf("Bad input.\nEnter angle in degrees: ");
    }

    int n = 1;
    float x = angle * M_PI / 180, a = sin(x), b = x, fact_num = 1, factor = x;
    while (fabsf(a - b) >= eps)
    {
        printf("n=%d is too small.\n", n);
        printf("sin(x)=%.18f\ttailor_sin(x)=%.18f\n", a, b);
        n++;
        fact_num += 2;
        factor = factor * x * x / fact_num / (fact_num - 1);
        if (n & 1)
            b += factor;
        else
            b -= factor;
    }
    printf("Seems like n=%d is enough.\n", n);
    printf("sin(x)=%.18f\ttailor_sin(x)=%.18f\n", a, b);

    return 0;
}