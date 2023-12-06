# My Algorithm (steps to solve the problem)

This program, involves implementing a feature already part of the python programming language called readlines. The purpose of this function is to be able to count and output the individual lines of text/characters that are contained in a file input by the user.

To implement this feature in C, there are few inbuilt functionalities, but the following twists is what makes it harder to complete which are part of the starter code : 
1. Appending the lines from the inut file to another storage container and then displaying each line individually.
2. Making sure that the memory used by each of the variables is dynamically allocated

# Structure of the readlines solution

In order to be able to count the number of lines present in a file input by the user, the program would have to perfor the following steps: 

1. check that each character, until the end of file is a new-line character. 
    - If it is, reallocate more memory for the container which holds the character in each line. 
    - To ahieve that, incement the number of lines that have been encountered.
    
2. If the check reveals that there is no new line detected, the program continues to append each charcter to the variable, and at the same time continues to allocate more space every time that each new character is appended to the container storing each of the character as read by the lines. 

# Conclusion

This continues until the end of the lines, and since the number of lines have been tracked, this value is passed on to the other helper functional features that make use of the value as part of the started code.

# Differences

There were no differences between my code and conceptual description.