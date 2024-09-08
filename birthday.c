#include <stdio.h>
#include <time.h>

int main()
{
    int bday, byear, bmonth, age;

    time_t currentTime = time(NULL);
    struct tm *localTime = localtime(&currentTime);

    int currentYear = localTime->tm_year + 1900;
    int currentDay = localTime->tm_mday + 1;
    int currentMonth = localTime->tm_mon;

    printf("what is your birthday (YYYY MM DD): ");
    if (scanf("%d %d %d", &byear, &bmonth, &bday) != 3)
    {
        fprintf(stderr, "please enter your birthday in YYYY MM DD format");
        return 1;
    }
    age = currentYear - byear;
    if (currentMonth < bmonth || (bmonth > currentMonth && currentDay < bday))
    {
        age--;
    }
    printf(" your age is: %d", age);
    return 0;
}