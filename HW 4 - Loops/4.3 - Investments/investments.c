/**
 * Program to calculate the amount a user should divide between an investment and
 * their loan payment.
 * It also gives a comparison of paying off your loans before investing any money.
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Function to reduce the loan amount by considering the interest rate and the payment
void DecreasedLoanPayment(double* loanRemaining, double rate, double payment){
    *loanRemaining += *loanRemaining*rate; // Applying interest
    *loanRemaining -= payment; // Reducing the loan by the payment
}

// Function to increase the investment amount considering the interest rate and additional investment
void IncreasedInvestment(double* investedAmount, double rate, double investmentAmount){
    *investedAmount += *investedAmount*rate; // Applying interest
    *investedAmount += investmentAmount; // Adding the investment amount
}

// Function to calculate the savings considering loans, investments, and monthly budget
void SavingsCalculator(double loanOwed, double loanPercent, double loanMoney,double monthlyBudget, int years, double* investmentBucket,
                       double investmentROR, bool* monthsExpired){

    *investmentBucket = 0; // To ensure the first month investment increase is 0.
    int months = years * 12;
    double rateLoan = loanPercent/12; // Convert annual rate to monthly
    double money = loanMoney;
    double rateInvest = investmentROR/12; // Convert annual rate to monthly
    double totalMoney = monthlyBudget;
    *monthsExpired = false; // Initializing expiration status

    if (money < 0.1){
        money = totalMoney;
    }

    do{
        DecreasedLoanPayment(&loanOwed, rateLoan, money);
        IncreasedInvestment(&*investmentBucket, rateInvest, totalMoney - money);
        months --;
    } while(loanOwed > 0 && months > 0);

    if(months > 0){
        *monthsExpired = false; // Setting expiration status
    } else {
        *monthsExpired = true; // Setting expiration status
    }

    if (loanOwed <= 0){
        *investmentBucket += fabs(loanOwed); // Adding remaining loan to the investment.
        do{
            IncreasedInvestment(&*investmentBucket, rateInvest, totalMoney); // Increasing investment
            months --;
        } while(months > 0);
    }

    if (loanOwed > 0 && months == 0){
        *investmentBucket -= loanOwed;
    }

}

// Function to emulate different payment scenarios for loans and investments
void MoneySplitEmulator(double loan, double loanRate, double loanPayment, double totalPayment,
                        int years, double investmentRate){
    double maxPaySavings;
    double minPaySavings;
    double amountInvested;
    bool retirementSavingsIsMin = true;
    bool haveMonthsExpired;

    if (loanRate >= investmentRate){
        retirementSavingsIsMin = false;
        SavingsCalculator(loan, loanRate, 0, totalPayment, years, &amountInvested,
                          investmentRate, &haveMonthsExpired);
        maxPaySavings = amountInvested;
        SavingsCalculator(loan, loanRate, loanPayment, totalPayment, years, &amountInvested,
                          investmentRate, &haveMonthsExpired);
        minPaySavings = amountInvested;
    } else {
        SavingsCalculator(loan, loanRate, loanPayment, totalPayment, years, &amountInvested,
                          investmentRate, &haveMonthsExpired);
        if (haveMonthsExpired){
            retirementSavingsIsMin = false;
            SavingsCalculator(loan, loanRate, 0, totalPayment, years, &amountInvested,
                              investmentRate, &haveMonthsExpired);
            maxPaySavings = amountInvested;
            SavingsCalculator(loan, loanRate, loanPayment, totalPayment, years, &amountInvested,
                              investmentRate, &haveMonthsExpired);
            minPaySavings = amountInvested;
        } else {
            retirementSavingsIsMin = true;
            minPaySavings = amountInvested;
            SavingsCalculator(loan, loanRate, 0, totalPayment, years, &amountInvested,
                              investmentRate, &haveMonthsExpired);
            maxPaySavings = amountInvested;
        }
    }

    if (retirementSavingsIsMin || minPaySavings >= maxPaySavings){
        printf("You should only make the minimum payments on your loan and apply the rest towards retirement.\n");
        printf("If you do you will have $%.2lf when you retire as opposed to $%.2lf if you paid off your loan"
               " before investing.\n", minPaySavings, maxPaySavings);
    } else {
        printf("You should apply all $%.2lf towards your loan before making any investments.\n", totalPayment);
        printf("If you do you will have $%.2lf when you retire as opposed to $%.2lf if you only "
               "made minimum payments.\n", maxPaySavings, minPaySavings);
    }

}

// Main function to handle user input
int main(void){

    double loanAmount;
    double annualInterestRate;
    double minPayment;
    double moneyMonthly;
    int ageNow;
    int ageRetire;
    double investmentReturnRates;
    int timeAvailable;


    do{
        printf("Enter how much you owe in loans: ");
        scanf(" %lf", &loanAmount);
    } while (loanAmount < 0);

    do{
        printf("Enter the annual interest rate of the loans: ");
        scanf(" %lf", &annualInterestRate);
    } while (annualInterestRate < 0);

    do{
        printf("Enter your minimum monthly loan payment: ");
        scanf(" %lf", &minPayment);
    } while (minPayment < 0);

    do{
        printf("Enter how much money you will be putting towards loans/retirement each month: ");
        scanf(" %lf", &moneyMonthly);
    } while (moneyMonthly < minPayment);

    do{
        printf("Enter your current age: ");
        scanf(" %d", &ageNow);
    } while (ageNow < 0);

    do{
        printf("Enter the age you plan to retire at: ");
        scanf(" %d", &ageRetire);
    } while (ageRetire < ageNow);

    do{
        printf("Enter your predicted annual rate of return: ");
        scanf(" %lf", &investmentReturnRates);
    } while(investmentReturnRates < 0);

    timeAvailable = ageRetire - ageNow;

    MoneySplitEmulator(loanAmount, annualInterestRate, minPayment, moneyMonthly,
                       timeAvailable, investmentReturnRates);

}