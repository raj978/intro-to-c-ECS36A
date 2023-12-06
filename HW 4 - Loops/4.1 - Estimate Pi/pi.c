/**
 * This program is to estimate the value of pi
 * It uses 3 functions to achieve this
 * The header file stdlib.h is used to get the random function
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

double rand_double(double low, double high)
{
    /*
     * generate a random double between low and high inclusive
     * @low: the lowest possible double that can be generated
     * @high: the highest possible double that can be generated
     * @returns: a random number between low and high
     */
    return low + ((double)rand()) / (((double)RAND_MAX / (high - low)));
}

double CircleBounds(double xInput)
{
    /**
     * This is a simple function which simply calculates the y coordinate/bounds of the circle
     * It is called by the IsInsideCircle function and returns a double value.
     */

    return (pow(1 - pow(xInput, 2.0), 0.5));
}

bool IsInsideCircle(double x, double y)
{
    /**
     * This function is used to check whether the randomly generated y variable lies within the circle
     * @param x is used to input the x coordinate that was randomly generated
     * @param y is used to input the y coordinate and is used to check whether the point lies in the circle
     * this function returns a boolean true if the point does exist and a false if it doesn't
     */
    y = fabs(y);
    if (CircleBounds(x) >= y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(void)
{
    /**
     * This function uses the below variables to store values
     * @seed is used to take in the input seed value
     * numInsideCircle is used to count the number of points that are inside the circle
     * numIterations is the number of iterations as required by the user input.
     * The x and y coordinates
     */

    int seed;
    int numIterations;
    int numInsideCircle;
    double xCoordinate;
    double yCoordinate;
    double probability;
    double pi;

    printf("Enter the seed for the random number generator: ");
    scanf(" %d", &seed);

    printf("Enter the number of iterations to run: ");
    scanf(" %d", &numIterations);

    srand(seed);
    numInsideCircle = 0;

    /**
     * the for loop is used to iterate numIteration times.
     * It is used to generate random points and check whether they lie inside the circle.
     * if points do lie, the variable @numInsideCircle is increased.
     */
    for (int i = 0; i < numIterations; ++i)
    {
        xCoordinate = rand_double(-1.0, 1.0);
        yCoordinate = rand_double(-1.0, 1.0);
        if (IsInsideCircle(xCoordinate, yCoordinate))
        {
            numInsideCircle++;
        }
    }
    probability =  (double)(numInsideCircle)/(double)(numIterations);
    pi = probability * 4.0;
    printf("The value of pi is %.2lf.\n", pi);

    return (0);
}