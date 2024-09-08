#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    char choice;
    do
    {

        int type;
        float A, B, Sum, Def, Mul, Dev;
        printf("Enter the values of A and B : \n");
        scanf("%f %f", &A, &B);

        Sum = A + B;
        Def = A - B;
        Mul = A * B;

        do
        {
            printf("what type type of equation you want: \n 1: addition \n 2: subtraction \n 3: multiplication \n 4: division \n");
            scanf("%d", &type);

            if (type < 1 || type > 4)
            {
                printf("please enter a valid choice");
            }

        } while (type < 1 && type > 4);
        if (type == 1)
        {
            printf("the result is: %.2f \n", Sum);
        }
        else if (type == 2)
        {
            printf("the result is %.2f \n", Def);
        }
        else if (type == 3)
        {
            printf("the result is %.2f \n", Mul);
        }
        else if (type == 4)
        {
            if (type == 4 && B == 0)
            {
                printf("Error: Division by zero is not allowed.\n");
                return 1;
            }
            Dev = A / B;
            printf("the result is %.2f \n", Dev);
        }

        printf("do you want to recalculate: \n");
        scanf(" %c", &choice);
    }

    while (choice == 'y' || choice == 'Y');

    return 0;
}
