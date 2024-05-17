#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

double cosSquared(double angle)
{
    double cosine = cos(angle);
    return pow(cosine, 2);
}

double suite(int n)
{
    double res = 0;
    for (int i = 1; i <= n; i++)
    {
        res = res + cosSquared((i * PI) / n);
    }
    return res / n;
}

int main()
{

    int n = 5;
    printf("the result of U%d = %.4lf \n", n, suite(n));

    return 0;
}
