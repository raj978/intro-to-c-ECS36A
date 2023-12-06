<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.7/MathJax.js?config=TeX-MML-AM_CHTML">
</script>

# Algorithm (steps to solve the problem)

This problem is relatively stratightforward wherein most of the inputs for the program are given and all that the algorithm needs to do is to solve for the monthly payment installments and from that calculation compute the value for the total amount.

## Calculating for the Monthly Loan Payment

The formula for calculating this value is :

$$
\text{Monthly Payment} = \frac{\text{Principal} \cdot \left(\frac{\text{Annual Interest Rate}}{12}\right)}{1 - \left(1 + \frac{\text{Annual Interest Rate}}{12}\right)^{-\text{Number of Months}}}
$$

###Calculating for the Total Amount
In this section, to obtin the value of the toal amount to be paid, keeping the interest rate in mind, we can get a vaue by multiplying the Montly Installments with the number of payments to be made. 

Finally, to calculate the difference between the principal amount and the total amount, we simply subtract the value of the prinicipal amont from the total amount.

## Integrating the formula into the solution

All that is remaining now is to integrate the above formula into the algorithm.

# Differences

There was one significant difference between the way I had planned to solve the problem and how I did end up solving the problem : this was in the division of the rate by 12, rather than the total number of payments.