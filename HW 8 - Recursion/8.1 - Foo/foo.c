//
// Created by Rajat Mahesh Gupta on 11/28/23.
//

#include <stdio.h>
#include <stdlib.h>

/**
 * This recursive function is used to call itself and return
 * value according to user input.
 * @param n : Is the value input by the user.
 * @return It returns an integer value giving the user the intended result.
 */
int foo(int n, int* memo) {
    if (n < 0) {
        return 0;
    }

    if (memo[n] != -1) {
        return memo[n];
    }

    switch (n) {
        case 0:
            memo[n] = 3;
            break;

        case 1:
            memo[n] = 6;
            break;

        case 2:
            memo[n] = 2;
            break;

        case 3:
            memo[n] = 7;
            break;

        default:
            memo[n] = foo(n - 1, memo) + foo(n - 2, memo) + foo(n - 3, memo) - foo(n - 4, memo) + 1;
            break;
    }

    return memo[n];
}

int main() {
    int* n = (int*)malloc(sizeof(int));
    int* finalVal = (int*)malloc(sizeof(int));

    printf("Enter a value for n: ");
    scanf("%d", n);

    // Allocate memory for memoization array
    int* memo = (int*)malloc((*n + 1) * sizeof(int));

    // Initialize memoization array with -1
    for (int i = 0; i <= *n; ++i) {
        memo[i] = -1;
    }

    *finalVal = foo(*n, memo);

    printf("Foo(%d) = %d\n", *n, *finalVal);

    // Free the memory assigned to variables during initialization
    free(n);
    free(finalVal);
    free(memo);

    return 0;
}
