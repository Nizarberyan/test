#include <stdio.h>;

int main() {
    int number1;
    int number2;

    printf("Type in the first number: \n");
    scanf("%d", &number1);

    printf("Type in the second number: \n");
    scanf("%d", &number2);

    if (number1 > number2) {
        printf("Number 1 is bigger\n");
    } else if (number2 > number1) {
        printf("Number 2 is bigger\n");
    } else {
        printf("The two numbers are equal\n");
    }

    return 0;
}
