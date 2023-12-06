# My Algorithm (steps to solve the problem)

The purpose of this program is to be able to compute the determinant of a matrix given the filename to the file containing the data on the values required for the computation. 

# Calculating the Determinant

In order to calculate the determinant, a matrix must be a minimum 2X2 in size and since the program input ensures that all the input matrices have a square size, they can be broken down into smaller components by creating smaller matrizes that are also squares in size.
    
In order to achieve this a repetitive function which simplfies the matrix into smaller squares until they are of a 2X2 dimension. Once, this is achieved, the function begans to calculate the determinant; this value is returned and the function keeps backtracking until 

# Structure of the Program to find the determinant

---

### Special sturucture to store the smaller matrices
Once the program is able to divide the matrix into 2X2 components then it can be strored in the struct and its determinants can be computed which can then be utilised to compute the rest of the determinants. 

### Function to access the data from the file

In order to be able to repeatedly access the contents storage container wherein the data from the matrix is stored a function is created with a base case that is able to call itself in case its functionality is not sufficed. 

In this case the base case will be : 
1. if the input row and column is equal to 1.
    In this case the total determinant of the input matrix would just be te single value that is present in the file.
    
2. If the current row and column of the selected matrix is 2X2.
    If the current row and column of the selected matrix, the value of the determinant as calculated from the formula below is calculated.
    
    ```det(A) = ad - bc```
    
    Here, the matrix A is represented as : 
    A = [ a b 
    
                                            c d ]
    
3. If the index at the first row has reached the end of the column, then the function prints out the value for the determinant of the entire matrix. 
    
**The repeating part of the function which will call itself : **

This function will use the value of another parameter that will be taken into account by the function call, which will determine the type of operation the matric is currently on. 
- The matrix determines its factor that is to be multiplied with the smaller matrix and finds the determinant of that smaller matrix, by recursively calling the function.

# Differences

There were no differences between the conceptual description and the programmatic implementation. One minor addition that was made to the code was the feature to free the matrix. This was made to get rid of the multiple instances of the Matrix datatype created.