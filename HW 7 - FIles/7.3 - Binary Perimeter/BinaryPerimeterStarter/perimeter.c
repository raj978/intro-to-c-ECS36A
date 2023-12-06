//
// Created by Rajat Mahesh Gupta on 11/26/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// This is the struct that is used to store the x and y
// coordinates of the points in the binar file
typedef struct {
    int x;
    int y;
} Point;

/**
 * This function is used to find the distance using Pythagoras' theorem
 * @param pointA : Is the first point from the list
 * @param pointB : Is the second point from the list
 * @return it returns the value of the distance which is a double data type.
 */
double findDistance(Point* pointA, Point* pointB) {
    return sqrt(pow(pointB->y - pointA->y, 2) + pow(pointB->x - pointA->x, 2));
}

/**
 * This function used to find the perimeter of the input file.
 * It uses the helper function getDistance to find the distance between each pair of consecutive points.
 * It then cumulates each of the points to a single perimeter variable which is passed out.
 * @param fp : Is the file pointer pointing to the binary file.
 * @param perimeter : It is the total perimeter as calculated from the function and passed to main function.
 */
void findPerimeter(FILE* fp, double* perimeter) {
    *perimeter = 0.0; // initializing perimeter to 0.
    int* numPoints = (int*) malloc(sizeof (int));
    fread(numPoints, sizeof(int), 1, fp);

    Point** points = (Point**)malloc(*numPoints * sizeof(Point*));

    // Variables used in the for loop
    int* i = (int*) malloc(sizeof (int));

    for (*i = 0; *i < *numPoints; ++*i) {
        points[*i] = (Point*)malloc(sizeof(Point));
        fread(points[*i], sizeof(Point), 1, fp);
    }

    for (*i = 0; *i < *numPoints - 1; ++*i) {
        *perimeter += findDistance(points[*i], points[*i + 1]);
    }
    *perimeter += findDistance(points[0], points[*numPoints - 1]);

    for (*i = 0; *i < *numPoints; ++*i) {
        free(points[*i]);
    }
    free(points);
}

int main(int argc, char** argv) {

    // This is used to check if the command line variables are valid.
    if (argc != 2) {
        printf("Usage:./perimeter.out <input_file>\n");
        return 0;
    }

    FILE* fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    double* perimeter = (double*)malloc(sizeof(double));

    // Function to find the perimeter.
    findPerimeter(fp, perimeter);

    // Displays the perimeter to the user.
    printf("The perimeter is %.2lf\n", *perimeter);

    fclose(fp);
    free(perimeter);

    return 0;
}
