/**
 * Created by Rajat Mahesh Gupta on 11/4/23.
 * This program is used to print the Pascal's triangle.
 * The program has 2 functions:
 * A 5 layer Pascal Triangle looks like:
 * 0: 1
 * 1: 1 1
 * 2: 1 2 1
 * 3: 1 3 3 1
 * 4: 1 4 6 4 1
*/

#include <stdio.h>

/**
 * The InsertPascalLine() function is used to calculate the values for each layers.
 * It takes in the parameters below to assist in the calculation and since its a void function,
 * it doesn't return any value except for the values of prevLayer and currLayer.
 * @param line : This is used to store the number of lines as obtained from user input.
 * @param prevLayer : This is the integer array that is used to store the values of the previous layer from the triangle.
 * @param currLayer : This too is an integer array that is uses prevLayer to calculate the values in the current layer.
 */

void InsertPascalLine(int line, int prevLayer[line], int currLayer[line+1]){
    for (int i = 0; i < line + 1; ++i){
        if (i == 0 || i == line){
            currLayer[i] = 1;
        } else {
            currLayer[i] = prevLayer[i-1] + prevLayer[i];
        }
    }
}

/**
 * The PrintTriangle function as described in the main function is used to print the entire pascal's triangle.
 * @param line : used to store the number of lines from user input.
 * @param pascalTriangle : Is the integer array that stores the values of all the layers of the Pascal's trinagle.
 */

void PrintTriangle(int line, int pascalTriangle[line-1][line]){
    for (int r = 0; r < line; ++r){
        for (int c = 0; c <= r; ++c){
            if (c != r){
                printf("%d ", pascalTriangle[r][c]);
            } else {
                printf("%d\n", pascalTriangle[r][c]);
            }
        }
    }
}

/**
 * Used to take in user input and call the 2 functions described above to print a given number of layers in the
 * Pascal's Triangle.
 * @return
 */
int main(void){
    int numLayers;

    printf("Please enter how many levels of Pascal's Triangle you would like to see: ");
    scanf("%d", &numLayers);

    int currTriangleLayer[numLayers];
    int prevLayer[numLayers];

    currTriangleLayer[0] = 1;

    int entireTriangle[numLayers][numLayers];

    // The for loop is used to iterate through the number of layers and calculate the values for current layers.
    for (int i = 0; i < numLayers; ++i){
        InsertPascalLine(i, prevLayer, currTriangleLayer);
        for (int j = 0; j <= i; ++j){
            entireTriangle[i][j] = currTriangleLayer[j]; // Add each element in currTriangleLayer to the Pascal triangle
            prevLayer[j] = currTriangleLayer[j]; // Copies currTriangleLayer to variable prevLayer.
        }
    }
    // The PrintTriangle function is used to print the entire pascal's triangle.
    PrintTriangle(numLayers, entireTriangle);

    return 0;
}

