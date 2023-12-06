#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void count(char *input, int *count) {
    *count = 0;
    for (int i = 0; i < strlen(input); ++i) {
        if (input[i] == 'x') {
            (*count)++;
        }
    }
}

void _print_comb_pattern(char *input, char *pattern) {
    char *d_input = strdup(input);
    int x = 0;

    for (int i = 0; i < strlen(input); ++i) {
        if (input[i] == 'x') {
            d_input[i] = pattern[x];
            x++;
        }
    }

    printf("%s\n", d_input);

    free(d_input);
}

void _print_pattern(char *input, char *pattern, int count, int k) {
    if (k == 0) {
        _print_comb_pattern(input, pattern);
    } else {
        pattern[count - k] = '0';
        _print_pattern(input, pattern, count, k - 1);

        pattern[count - k] = '1';
        _print_pattern(input, pattern, count, k - 1);
    }
}

void print_pattern(char *input, int count) {
    char *pattern = (char *)malloc(count * sizeof(char));
    _print_pattern(input, pattern, count, count);
    free(pattern);
}

void to_lower(char *input, char *argv) {
    strcpy(input, argv);

    for (int i = 0; i < strlen(input); ++i) {
        input[i] = tolower(input[i]); // Converts each character to lower case
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_string>\n", argv[0]);
        return 1;
    }

    char *input = (char *)malloc(strlen(argv[1]) + 1);
    int num = 0;

    to_lower(input, argv[1]);
    count(input, &num);

    if (num != 0) {
        print_pattern(input, num);
    } else {
        printf("%s\n", input);
    }

    free(input);

    return 0;
}
