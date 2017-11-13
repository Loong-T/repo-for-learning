#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char checksum = -1;
    char input;

    while ((input = getchar()) != EOF) {
        printf("%c", input);

        checksum += input;
        if (input == '\n') {
            printf("%d\n", checksum);
        }
    }

    return EXIT_SUCCESS;
}