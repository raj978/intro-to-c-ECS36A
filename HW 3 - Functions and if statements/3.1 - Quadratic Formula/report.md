<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.7/MathJax.js?config=TeX-MML-AM_CHTML">
</script>

# My Algorithm (steps to solve the problem)

This is a program that is meant to solve Quadratic equations in the form : 
```a * x^2 + b * x + c```

### The Quadratic Formula
In order to solve this problem, mathematics suggests a solution using a formula called the Quadratic formula which works by inputing the values three real numbers from the user input into the formula. 

$$
x = \frac{-b \pm \sqrt{b^2 - 4ac}}{2a}
$$

Variable : 
- a is the first user input or the coefficient of the largest exponent in the quadratic equation. 
- b is the second user input and is the coefficient of the exponent with a singular power.
- c is the constant value in the formula. 

## Problem Solving
In order to find the real solutions to this problem, the program must be able to evaluate the answer to the formula. Although, there are some caveats to this situation. Since the formula contains a sqaure root, if the value of the equation inside the square root evaluates to a negative value, there would be no real solution. Hence, below are the 2 different cases showing the programs response to different input values. 

### Case 1 : Real Output
If the value of 4 times a times c subtracted from the square of b, evaluated to a positive value there can be 2 different resulting situations. 
#### Single Root
Owing to the plus minus operation in the formula, the programmatic implementation of this will have 2 calculations to get the final answers. If both these evaluate to te equal to each other this would mean that the quadratic equation only has one root. 

#### Two Roots
As described in the Single Root description, if the value output by the 2 different calculations for the roots to the quadratic equations are not the same, then the program would output 2 different answers. 

### Case 2 : No Real Output
As mentioned in case 1, in case the value of 4 times a times c subtracted from the square of b, evaluated to a negative value, a square root cannot be calculated since negative numbers don't have a square root. 

## Conclusion
Now that the program is able to successfully handle all the input and output situations, below is the structure that will be used to solve the problem. 
1. Declaring variables
2. Function to calculate the square root
3. Obtaining the inputs for the Quadratic Equation
4. Conditional statement to determine the number of roots
5. Output the results

# Difference 
Although most of the structure of my code followed the structure I highlighted above, I had to define 2 different functions to find the 2 different roots and then compare them inside the main function.