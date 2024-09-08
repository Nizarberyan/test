#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int byear, bmonth, bday;
int age;
time_t currentTime = time(NULL);
struct tm *localTime = localtime(&currentTime);

int currentYear = localTime->tm_year + 1900;  // Add 1900 for actual year
int currentMonth = localTime->tm_mon + 1;  // Month is 0-indexed
int currentDay = localTime->tm_mday;
int main() {
   printf("whats your birth day (YYYY MM DD: \n)");
   scanf("%d,%d,%d",&byear, &bmonth, &bday );
   age = currentYear - byear;
   printf("%d", age);
   return 0;

}
