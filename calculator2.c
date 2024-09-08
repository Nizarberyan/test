#include <stdio.h>
#include <math.h>

int main()
{
    int choice;

    printf("Welcome to the Simple Calculator!\n");

    do
    {
        float firstNumber, secondNumber, result;

        printf("\nChoose an operation:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Percentage calculation\n");
        printf("6. Square root\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a number between 1 and 7.\n");
            scanf("%*[^\n]");
            continue;
        }

        switch (choice)
        {
        case 1:
            printf("Enter the first number: ");
            if (scanf("%f", &firstNumber) != 1)
            {
                printf("Invalid input. Please enter a number.\n");
                scanf("%*[^\n]");
                continue;
            }

            printf("Enter the second number: ");
            if (scanf("%f", &secondNumber) != 1)
            {
                printf("Invalid input. Please enter a number.\n");
                scanf("%*[^\n]");
                continue;
            }

            result = firstNumber + secondNumber;
            printf("The result of addition is: %.2f\n", result);
            break;

        case 2:
            printf("Enter the first number: ");
            if (scanf("%f", &firstNumber) != 1)
            {
                printf("Invalid input. Please enter a number.\n");
                scanf("%*[^\n]");
                continue;
            }

            printf("Enter the second number: ");
            if (scanf("%f", &secondNumber) != 1)
            {
                printf("Invalid input. Please enter a number.\n");
                scanf("%*[^\n]");
                continue;
            }

            result = firstNumber - secondNumber;
            printf("The result of subtraction is: %.2f\n", result);
            break;

        case 3:
            printf("Enter the first number: ");
            if (scanf("%f", &firstNumber) != 1)
            {
                printf("Invalid input. Please enter a number.\n");
                scanf("%*[^\n]");
                continue;
            }

            printf("Enter the second number: ");
            if (scanf("%f", &secondNumber) != 1)
            {
                printf("Invalid input. Please enter a number.\n");
                scanf("%*[^\n]");
                continue;
            }

            result = firstNumber * secondNumber;
            printf("The result of multiplication is: %.2f\n", result);
            break;

        case 4:
            printf("Enter the first number: ");
            if (scanf("%f", &firstNumber) != 1)
            {
                printf("Invalid input. Please enter a number.\n");
                scanf("%*[^\n]");
                continue;
            }

            printf("Enter the second number: ");
            if (scanf("%f", &secondNumber) != 1)
            {
                printf("Invalid input. Please enter a number.\n");
                scanf("%*[^\n]");
                continue;
            }

            if (secondNumber == 0)
            {
                printf("Error: Division by zero is not allowed.\n");
            }
            else
            {
                result = firstNumber / secondNumber;
                printf("The result of division is: %.2f\n", result);
            }
            break;

        case 5:
            printf("Enter the first number: ");
            if (scanf("%f", &firstNumber) != 1)
            {
                printf("Invalid input. Please enter a number.\n");
                scanf("%*[^\n]");
                continue;
            }

            int percentageChoice;
            printf("What do you want to find the percentage of?\n");
            printf("1. Find percentage of first number (second number is the percentage)\n");
            printf("2. Find what percentage of the second number is the first number\n");
            if (scanf("%d", &percentageChoice) != 1)
            {
                printf("Invalid input. Please enter 1 or 2.\n");
                scanf("%*[^\n]");
                continue;
            }

            if (percentageChoice == 1)
            {
                printf("Enter the percentage value (e.g., 10 for 10%%): ");
                if (scanf("%f", &secondNumber) != 1)
                {
                    printf("Invalid input. Please enter a number.\n");
                    scanf("%*[^\n]");
                    continue;
                }
                result = firstNumber * (secondNumber / 100.0);
                printf("%.2f%% of %.2f is %.2f\n", secondNumber, firstNumber, result);
            }
            else if (percentageChoice == 2)
            {
                printf("Enter the second number: ");
                if (scanf("%f", &secondNumber) != 1)
                {
                    printf("Invalid input. Please enter a number.\n");
                    scanf("%*[^\n]");
                    continue;
                }
                if (secondNumber == 0)
                {
                    printf("Error: Cannot find percentage of zero.\n");
                }
                else
                {
                    result = (firstNumber / secondNumber) * 100.0;
                    printf("%.2f is %.2f%% of %.2f\n", firstNumber, result, secondNumber);
                }
            }
            else
            {
                printf("Invalid choice. Please enter 1 or 2.\n");
            }
            break;

        case 6:
            printf("Enter the number to find the square root of: ");
            if (scanf("%f", &firstNumber) != 1)
            {
                printf("Invalid input. Please enter a number.\n");
                scanf("%*[^\n]");
                continue;
            }
            if (firstNumber < 0)
            {
                printf("Error: Square root of a negative number is not real.\n");
            }
            else
            {
                result = sqrt(firstNumber);
                printf("The square root of %.2f is %.2f\n", firstNumber, result);
            }
            break;

        case 7:
            printf("Exiting the calculator. Goodbye!\n");
            break;

        default:
            printf("Invalid choice. Please enter a number between 1 and 7.\n");
            break;
        }
    } while (choice != 7);

    return 0;
}
