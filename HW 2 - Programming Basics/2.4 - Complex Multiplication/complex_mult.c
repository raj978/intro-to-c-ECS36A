#include <stdio.h>

int main(void){
    int real1 = 0;
    int real2 = 0;
    int complex1 = 0;
    int complex2 = 0;

    // To input the first complex number
    printf("Enter the first complex number in the form ai + b: ");
    scanf("%d i + %d", &complex1, &real1);
    printf("\n");

    // TO input the second complex number
    printf("Enter the second complex number in the form ai + b: ");
    scanf("%d i + %d", &complex2, &real2);
    printf("\n");

    int computedReal = (real1 * real2) - (complex1 * complex2);
    int computedImag = (real1 * complex2) + (real2 * complex1);

    printf("(%di + %d) * (%di + %d) = %di + %d\n", complex1, real1, complex2, real2, computedImag, computedReal);

}