#include <stdio.h>
int main()
{
    int age;
    char sex;
    printf("enter you age : ");
    scanf("%d", &age);
    printf("enter you sex : ");
    scanf(" %s", &sex);

    if (sex == 'm' && age > 20)
    {
        printf("impossible");
    }
    else if (sex == 'f' && age >= 18 && age <= 35)
    {
        printf("impossible");
    }
    else
    {
        printf(" nom impossible");
    }

    return 0;
}