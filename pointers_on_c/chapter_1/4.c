#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int main(void)
{
    char line[MAX_LENGTH];
    char max_line[MAX_LENGTH];

    while (fgets(line, MAX_LENGTH, stdin) != NULL) {
        if (strlen(line) > strlen(max_line)) {
            strncpy(max_line, line, MAX_LENGTH);
        }
    }

    printf("%s", max_line);

    return EXIT_SUCCESS;
}