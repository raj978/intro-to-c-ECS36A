# Algorithm (steps to solve the problem)
## Understanding the problem

This problem is used to verify whether 2 words input by the users are anagrams or not. In order to this the program must be able to input the 2 phrases and then check whether each of the letters in the 2 phrases are the same or not. An important factor to keep in check is that this comparison must be case in-sensitive. This means that the program should compare the values irrespective of their case. 

## Problem Abstraction 

This program is stratightforward in its implementation, since it must be able to input the values, chaange its case. And then have another second function to check for replicability. Below are the steps which the program must be able to perform in the same order. 

In order to achieve the above steps the program would contain the following functions:

1. Function to arrange the input and store it
2. Function to check one variable against another.
3. Function to get the user input to lower case.

#### Function to arrange the input and store it.

This function essentially goes through all the elements stored in the user input and arranges it in alphabetical order by reffring to numerical values associated with that element.

#### Function to check one variable against another
This function takes it both the inputs by the user and after making sure they are of the same length, checks each element to see if they are the same. This process is a lot more efficient once we have arranged the elements in alphabetical order as performed by the function above.

#### Function to convert user input to lower case
In order to ensure that the comparison, done by the previous function is useful, it is essential that the input be converted into the same case, in this case - lower case was chosen. 

## Conclusion 
Thus with the help of the 3 functions, and a basic condition that allows the program to consider the input as an anagram if both the strings input by the user are of the same length and then output a certain result if they the same and different if they are not.
# Differences
There were no differences between my initial conceptual description and the programmatic implementation.