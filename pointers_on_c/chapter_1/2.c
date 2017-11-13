#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int line_count = 1;
    int new_line = 1;
    char input;

    while ((input = getchar()) != EOF) {
        if (new_line) {
            printf("%d\t", line_count++);
            new_line = 0;
        }
        if (input == '\n') {
            new_line = 1;
        }

        printf("%c", input);
    }

    return EXIT_SUCCESS;
}