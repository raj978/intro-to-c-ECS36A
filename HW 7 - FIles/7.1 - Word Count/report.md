# My Algorithm (steps to solve the problem)

This progra is designed to count the number of words that are read from a file. Here the only twist is provided by the following 2 constratraints: 
1. Dynamic Memory Allocation - This would mean that the size of the array used to store the user input would have to change at the time of recieving in comparison to its value at the time its defined. 
2. A word is 1 or more consecutive non-whitespace character

# Structure of the solution program

## Input from user

This functional component of the program would be targeted to take in input from the user and dynamically allocate a storage space to store the input. 

## Function to calculate the number of words in the input

This function simply accesses the storage space with the user input, repeats through the individual character in the container and counts the number of words if they are 1 or more non-whitespace charactes - which can be verified using an inbuilt C feature. 

# Conclusion

In this way, the program is then able to output the counted characters to the user.

# Differences

There were no differences between my conceptual description and my programmatic implementation.