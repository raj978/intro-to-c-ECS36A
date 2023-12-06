# Algorithm (steps to solve the problem)

This problem involved finding the percentage that the user would need to get in the finals, to be able to achieve the grade they desire to achieve in the class. 

## Problem Abstraction 

In order to solve this problem, the user needs to provide the following inputs : 
1. Desired Grade 
2. Percentage corresponding to that grade. 
3. Weight of the Final.
4. Current grade percentage (Out of these inputs, to calculate the grade in the final, only the values for 2, 3 and 4 are important.)

## Calculation for the grade to be achieved in the Final exam

This value can be calculated using the following steps : 
1. Finding the Weightage of the current grade 
    
     This can be done by multiplying the Current grade percent with the percentage of the grade that is **not made up** of the final. 

2. Subtaracting the weightage of the current grade from the desired grade
    
    Once the value for the weigtage of the whole grade made up by your current grade is found, the value for the weightage of the grade made by the final is calculated by subtracting the value of the current weightage from the desired grade.

3. Finding the weightage of the total grade made up by the Final
    
    After getting the value of the weightage of the grade made up by the final, the percentage of the final can be found by dividing the weightage captured by the final.

4. Finding the percentage required in the final
    

## Displaying the result

Now that we have the value of the percentage that the user must secure in the final, we can display the result as an output of the algorithm along with the letter grade associated with that percentage.
# Differences

There were no diffference between the way I planned to solve the problem and the algorithm that I used for the implementation of the problem.