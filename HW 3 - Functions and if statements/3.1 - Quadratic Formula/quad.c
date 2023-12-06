#include <stdio.h>
#include <math.h>
/*Importing math.h to allow for the use of the pow funciton*/

/*This program is used to find the roots for a quadratic equation by taking in inputs from the user.*/

double FindFirstRoot(double a, double b, double c){
    /*This function is used to find the first root*/

    /*All three input a, b and c are doubles to allow for decimal values. a is used to store the coefficitent to the exponent with the highest power, b is the coefficient of the exponent with a power of 1 and finally c is the constant in the quadrtic equation*/

    double root;

    /* root is the variable to store the value output from the formula below*/

    root = (-b + pow(pow(b, 2) - (4 * a * c),0.5)) / ( 2 * a );
    return root;
    /*This function will return the value of the second root as a double data type*/
}
double FindSecondRoot(double a, double b, double c){
    /*This function is used to find the second root*/

    /*All three input a, b and c are doubles to allow for decimal values. a is used to store the coefficitent to the exponent with the highest power, b is the coefficient of the exponent with a power of 1 and finally c is the constant in the quadrtic equation*/

    double root;

    /* root is the variable to store the value output from the formula below*/
    root = (-b - pow(pow(b, 2) - (4 * a * c),0.5)) / ( 2 * a );
    return root;
    /*This function will return the value of the second root as a double data type*/
}

int main(void){
    double a;
    double b;
    double c;
    // As described int the functions a, b and c are used to store user input

    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf("%lf", &a);
    printf("Please enter b: ");
    scanf("%lf", &b);
    printf("Please enter c: ");
    scanf("%lf", &c);

    double rootOne;
    double rootTwo;
    if (pow(b, 2)  - (4 * a * c) >= 0){ /* This conditional is used to make sure that the program doesn't spit out an error resulting from square rooting a negative number*/
        rootOne = FindFirstRoot(a, b, c);
        rootTwo = FindSecondRoot(a, b, c);
    } else {
        printf("There are no real solutions\n");
        return 0;
    }

    if(fabs(rootOne - rootTwo) > 0.000001){
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", rootOne);
        printf("Solution 2: %.2lf\n", rootTwo);
        return 0;
    } else if (fabs(rootOne - rootTwo) < 0.000001){
        printf("There is one real solution: %.2lf\n", rootOne);
        return 0;
    }
}
    