# Algorithm (steps to solve the problem)

The purpose of this program is to help the user understand whether its a good idea to contribute a minimum amount of money to pay off a loan and invest the rest so that it grows by the time they retire, or to pay off their loans first before they decide to retire. 

## Problem Abstraction
The essence of the problem lies in 2 concepts, mainly compound interest calculations and smart decision making. Programmatically speaking, this program can be broken down into the following functions : 

1. Function to calculate decreasing loan amount to be paid
2. Function to calculate increasing value of the money invested until retirement
3. Function to calculate whether or not loan is paid in full before retirement
4. Function to emulate the situations on splitting the monthly money
5. Main Function 

Now that the functions to be used have been enumerated above, below is the description of the detailed operations that will occur.

#### Function to calculate decreasing loan amount to be paid
Since this a simple function that can be used to calculate the final value of the loans appreciation at the end of the month, it first calculates the increased value of the loan due to the interest rate. Then reduces the amount from the minimum or total loan/investment amount and outputs the remaining decreased value of the loan that is yet to be paid. 

    It also ensures that its subtracting only enough money from the loan amount till its less than or equal to 0. in case the loan does reach 0, adding the remaining account back into the investment category at the start of the month after the interest rate on the investment is calculated and the additional money to be spend on investing is added.
    
#### Function to calculate the increasing value of the money invested until retirement
Just like the function above, this is like a function that is called each time by another parent function and is responsible for calculating the increase in investment each month depending on the amount of money that is fed as input.
    
#### Function to calculate whether or not the loan is paid in full
This is the wrapper function which is used by another parent function but does most of the heavy lifting when it comes to calculating the values for the amount left for retirement in both the cases when the minimum amount is used to pay the loan, and when the entire montly budget is spent on the loan. 

    Some of the key features this function contains include: 
    
        1. Containing a cutoff to stop calling the function to decrease the loan amount when the function returns a negative value. It then calculates the excess amount and inserts it into the investment bucket after calcularing the increased investment for that month.
        2. Containing another cutoff to increase the amount being invested once the function used to decrease the loan amount returns a negative or 0 value. 
        3. Ensuring that the first call given to the function increasing the money that is invested has the money being invested at 0.
        4. The money dedicated towards investing is added after the function to increase investment is called.

#### Function to emulate the situations on splitting the monthly money
This funciton will utilize the function to to determine whether or not the loan is paid in full in order to output the right statement on which method would yield higher savings. Depending on the user inputs, the program might encounter the following situations:

1. Case 1 : This is when the interest rate of your loan payment is greater than interest rate of the investments, in this case, the user would be losing money by not paying off their loans first and investing the 
the value for the minimum loan payment is subtracted from the total loan to be paid at the start of each month until the loan payment is reduced to 0 before retirement is reached. 

2. Case 2: For any interest rate on the loan that is less than or equal to the amount to the interest rate on the investments; the calculation for the loan amount being subtracted by the minimum money reserved to pay off the loans is less than or equal to 0, before the retirement age is reached, then the minimum amount to pay the loan should suffice. 

3. Case 3: This is when case 2 doesn't occur and so the program defaults to paying the enitre loan/investment amount towards first paying off the loan and then redirecting the rest of the amount towards savings. 

#### Main Function 
This function is making sure the user input is valid, by repeatedly reprompting the user to input the right values in case they are incorrect. 
It doesn't do anything major other than calling the function that emulates the cases based on the values input by the user. 

## Conclusion
Thus, the final ouput would be produced by the function that emulates the functions 
# Differences
There were virtually no differences between my initial concept and actual code, the only changes that I made were cahnging the way the most optimal savings were displayed by comparing the values from 2 different calculations. This is a function that I included in my emulation function that I didn't initially mention in the concept description.