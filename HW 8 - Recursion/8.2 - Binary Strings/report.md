# My Algorithm (steps to solve the problem)

This program is used to covert the x's in the user input to combinations of 0s and 1s. The program checks the user input if there are any Xs in the input and displaces them with 0s and 1s. 

## Program Structure 

1. Take user input

2. Change the user input to lower case

3. Repeatedly called feature to output the final combinations of binary values. 
    - This function uses the helper feature count X - which counts the number of the x's and outputs the number of combinations that the program needs to output. 
    
    - From the count, it now uses another storage container of a data type that can store multiple properties at a particular index. 
    
    - These values are then substitutes into the rest of the numbers as they are output to the user.
    
    
# Conclusion

In this way the program is able to display the combination of 0s and 1s to the user.

# Differences

There are several key differences that I had to make to allow for a smooth implementation of a program that was able to generate patterns that suited the user input: 
1. Divide the funcitons which prints the pattern, the array that computes the pattern and the central feature that allocates a new pattern for each line. 

2. The method to create the repeated function that created the pattern, it uses backtracked values to create a binary battern where each repeated call only flips one bit starting from the right edge to the left edge.

3. The third chage was that to display the final value of binary string, the user input string was duplicated and values of the x were substituted with the values stored in the pattern and then this duplicated input container is displayed to the user.