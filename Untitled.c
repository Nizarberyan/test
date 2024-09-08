#include <stdio.h>
#include <math.h>

int main()
{
    int num, i, is_prime = 1;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if (num <= 1)
    {
        is_prime = 0;
    }
    else if (num <= 3)
    {
        is_prime = 1;
    }
    else if (num % 2 == 0 || num % 3 == 0)
    {
        is_prime = 0;
    }
    else
    {
        for (i = 5; i * i <= num; i += 6)
        {
            if (num % i == 0 || num % (i + 2) == 0)
            {
                is_prime = 0;
                break;
            }
        }
    }

    if (is_prime)
    {
        printf("%d is a prime number\n", num);
    }
    else
    {
        printf("%d is not a prime number\n", num);
    }

    return 0;
}
