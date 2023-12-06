# Algorithm (steps to solve the problem)

This program is used to output, a given number of layers of the Pascal's Triangle. 

## Problem Abstraction
This problem involved creating the Pascal's triangle without using any combinatorics, multiplication or any convenient ways to store large numerical values.

Thus the program would consist of the following functions: 
1. Function to calculate the values for each individual layer.
2. Function to print the entire Pascal's triangle
3. The Main Function

#### Funciton to calculate the values for each individual layer.

This function essentially, uses 2 storage containes one of which is used to store the calculations for the current layer of pascal's triangle, the latter of which has the values from the previous layer and is used to calculate the values for the current layers. 

It does this keeping in mind that the first and last position of each layer is 1.

#### Function to print the entire Pascal's triangle

This function is used to print all the values of the pascals triangle.

#### The main function

The main function is used to take in the user input on the number of layers of the Pascal's triangle to input and also calls the 2 previous functions to print these layers.

## Conclusion
In this way, by using 2 functions as well as avoiding the use of any complex data types, avoiding the use of the multiplication operators the program is able to print a pre-determined number of layers of the Pascal's triangle.

# Differences
There were virtually no differences between my prorammatic implementation and my initial conceptual description.