#include <stdio.h>
#include <time.h>

int byear, bmonth, bday;
int age;

int main()
{
    // Get current date
    time_t currentTime = time(NULL);
    struct tm *localTime = localtime(&currentTime);

    int currentYear = localTime->tm_year + 1900;
    int currentMonth = localTime->tm_mon + 1;
    int currentDay = localTime->tm_mday;

    // Get user's date of birth
    printf("Enter your date of birth (YYYY MM DD): ");
    if (scanf("%d %d %d", &byear, &bmonth, &bday) != 3)
    {
        fprintf(stderr, "Error: Invalid input format. Please enter in YYYY MM DD format.\n");
        return 1; // Indicate error
    }

    // Calculate age, considering incomplete birthdays
    age = currentYear - byear;
    if (currentMonth < bmonth || (currentMonth == bmonth && currentDay < bday))
    {
        age--; // Decrement age if birthday hasn't happened this year yet
    }

    printf("Your age is: %d\n", age);

    return 0;
}
