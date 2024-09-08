#include <stdio.h>;

int main()
{

    int number1;
    int number2;

    printf("type in the first number: \n");
    scanf("%d", &number1);

    printf("type in the second number: \n");
    scanf("%d", number2);

    if (number1 > number2)
    {
        printf("number 1 is bigger \n");
    }
    else if (number1 < number2)
    {
        printf("number 2 is bigger \n");
    }
    else
    {
        printf("the two numbers are equal");
    }

    return 0;
}