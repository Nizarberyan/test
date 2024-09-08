#include <stdio.h>
#include <math.h>

float area;
float parameter;
float length;
float width;
char power[] = "²";
char unit;

int main()
{
    printf("please enter the length of the rectangle : \n");
    scanf("%f", &length);

    printf("please enter the width of the rectangle : \n");
    scanf("%f", &width);

    printf("please enter the unit of measurement: \n");
    scanf(" %c", &unit);

    area = width * length;
    parameter = 2 * (length + width);

    printf("the area of the rectangle is : %f %c%c\u00B2 \n", area, unit, power);
    printf("the parameter of the rectangle is %f %c", parameter, unit);

    return 0;
}