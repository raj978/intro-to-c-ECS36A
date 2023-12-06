#include <stdio.h>

int main(void){
    char letter[5];
    double desiredGrade;
    double currentGrade;
    double finalGrade;
    double finalWeight;

    // Input for desired letter grade
    printf("Enter the grade you want in the class: ");
    scanf("%s", letter);
    printf("\n");

    // Input for desired grade percentage
    printf("Enter the percent you need to get that grade: ");
    scanf("%lf", &desiredGrade);
    printf("\n");

    // Input for current grade percentage
    printf("Enter your current percent in the class: ");
    scanf("%lf", &currentGrade);
    printf("\n");

    // Input for the weight of the final
    printf("Enter the weight of the final: ");
    scanf("%lf", &finalWeight);
    printf("\n");

    finalGrade = ((desiredGrade/100 - ((1-(finalWeight/100)) * currentGrade/100)) / (finalWeight/100));

    printf("You need to get at least %.2lf%% on the final to get a %s in the class.\n", finalGrade*100, letter);
}