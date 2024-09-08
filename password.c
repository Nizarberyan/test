#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *generate_password(int length)
{
    char *password = malloc(length + 1);
    char *charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()";

    // Seed the random number generator with system time
    srand(time(NULL));

    for (int i = 0; i < length; i++)
    {
        password[i] = charset[rand() % strlen(charset)];
    }

    password[length] = '\0'; // Null-terminate the string

    return password;
}

int main()
{
    int length;

    printf("Enter desired password length: ");
    scanf("%d", &length);

    char *password = generate_password(length);
    printf("Generated password: %s\n", password);

    printf("\nPassword generated successfully. Press any key to exit.\n");
    getchar(); // Wait for user input

    free(password);
    return 0;
}
