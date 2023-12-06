#include <stdio.h>
#include <math.h>

int main(void){
    double principal;
    double rate;
    int numPayments;
    double monthlyPayments;
    double totalAmount;
    
    // To collect value for Principal amount
    printf("Please enter the amount of money you borrowed: $");
    scanf("%lf", &principal);
    printf("\n");

    // To collecvt the value for the Interest rate
    printf("Please enter the annual interest rate: ");
    scanf("%lf", &rate);
    printf("\n");

    // To collect the value for the number of payments
    printf("Please enter the number of payments to be made: ");
    scanf("%d", &numPayments);
    printf("\n");

    monthlyPayments = (principal * (rate / 12)) / (1 - pow(1 + (rate / 12), -numPayments) );

    totalAmount = monthlyPayments * numPayments;

    printf("A loan of $%.2lf with an annual interest of %.2lf paid off over %d months will have monthly payments of $%.2lf.\n\n", principal, rate, numPayments, monthlyPayments);

    printf("In total, you will pay $%.2lf, making the cost of your loan $%.2lf.\n", totalAmount, totalAmount - principal);

}
