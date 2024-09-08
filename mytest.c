#include <stdio.h>;

int main()
{
    int age;
    char sex;

    printf("enter your age: ");
    scanf("%d", &age);

    printf("enter your sex: ");
    scanf(" %c", &sex);

    if (sex == 'm' && age >= 20)
    {
        printf("you qualify. \n");
    }
    else
    {
        printf("just no. \n");
    }

    return 0;
}