#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 20
#define MAX_INPUT 1000

int read_column_numbers(int columns[], int max);
void rearrange(char *output, char const *input, int n_columns, int const columns[]);

int main(void)
{
    int n_columns;
    int columns[MAX_COLS];
    char input[MAX_INPUT];
    char output[MAX_INPUT];

    n_columns = read_column_numbers(columns, MAX_COLS);

    while (gets(input) != NULL) {
        printf("Original input: %s\n", input);
        rearrange(output, input, n_columns, columns);
        printf("Rearranged line: %s\n", output);
    }

    return EXIT_SUCCESS;
}

int read_column_numbers(int columns[], int max)
{
    int num = 0;
    int ch;

    while (num < max && scanf("%d", &columns[num]) == 1 && columns[num] >= 0) {
        num += 1;
    }

    if (num % 2 != 0) {
        puts("Last column number is not paired.");
        exit(EXIT_FAILURE);
    }

    while ((ch = getchar()) != EOF && ch != '\n') {
        ; // pass
    }

    return num;
}

void rearrange(char *output, char const *input, int n_columns, int const columns[])
{
    int output_col = 0;
    int len = strlen(input);

    for (int col = 0; col < n_columns; col += 2) {
        if (columns[col] >= len) {
            continue;
        }
        if (output_col == MAX_INPUT - 1) {
            break;
        }

        int nchars = columns[col + 1] - columns[col] + 1;

        if (output_col + nchars >= MAX_INPUT) {
            nchars = MAX_INPUT - output_col - 1;
        }
        if (columns[col] + nchars - 1 >= len) {
            nchars = len - columns[col];
        }

        strncpy(output + output_col, input + columns[col], nchars);
        output_col += nchars;
    }

    output[output_col] = '\0';
}