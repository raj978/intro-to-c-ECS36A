# Algorithm (steps to solve the problem)

## Understanding the problem
This program is used as a method to prove how points generated inside a 2x2 sqaure with a circle inscribed in a square can be used to estimate the value of pie on the basis of the formula used to calculate the area of the 2x2. 

Using probability, the program will create random points on a grid whose x axis extends from [-1, 1] and the y-axis which extends from [-1, 1]. Check whether these points lie inside the circle or not. And depending on the number of points the user asks to generate, the more likely it is for the program to estimate a more accurate value for pi. 

## Problem Abstraction

This program must have 3 functions which include : 
1. Function to check whether the point lies within the circle
2. Function to generate random points
3. Main Function
Addittional Function : Function to calculate the bounds / points of the circle

## Function to validate random point's positioning with circle
This function would need to be able to take the random points' x and y coordinates as input and using the formula for the equation of a circle find out whether the y cordinate of the circle at the same x value is greater than the y coordinate of the circle (if the point is in the 1st or 2nd quadrand of the grid). But if the point is on the 3rd or 4th quadrant then the y coordinate of the point would be larger than that of the value provided by the equation of the circle. 

The equation of the circle to be used in the program is : ```x^2 + y^2 = 1```

An important thing to consider is that the equation of a circle does not map values one-to-one which means that inputing the value x = 0.5, would give y = 0.866. But its impotant to consider that this value is on the 1st quadrant. The circle also has a point on the opposite quadrant (i.e. the 4th quadrant). In order to simplify this problem, any y coordinate will simply be converted to a positive value and then compared with the corresponding positive value of the y coordinate of the circle.

## Function to generate random points

This function will be the outer function which will call the position validation function, it will cycle through the number of point generation as requested by the user and each time a new point is created, it will call the checking position above. 

    Depending on the output from the checker, it will count the number of points inside the circle and output the value of pi. 
    
## The main Function
The main function is where the user will be able to enter the input and be able to call the function to generate the random points. The function returns the value of pi which is output by the main function.

# Differences

The only change that I made to my code was to add another function to calculate the bounds of the circle so that I could make sure that I have 3 separate functions apart from the main function.