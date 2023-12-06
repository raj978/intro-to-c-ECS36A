<script type="text/javascript" async
    src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.7/MathJax.js?config=TeX-MML-AM_CHTML">
 </script>
# My Algorithm (steps to solve the problem)

The purpose of this program is to be able to find the total perimeter from the points present in an input file containing binary data. What this means is that the data in the file is not stored in a plain text format. Rather its stored in a special format of 0s and 1s which are designed to be read by a computer. 

This .bin file contains valid data with the number of points mentioned on the first line, followed by the x and y coordinates of the points. The program must be able to go through each point, find the distance between each of the correcponding points in a way that they form a convex 2D shape.

# Structure of the perimeter solution
1. Iterating through the total number of points and computing the ditance between every combination of 2points that can be selected with the given number of points. 

2. The distance is found using Pythagoras' theorem. 
    <p> \[ d(distance) = \sqrt{a^2 + b^2} \] </p>
    In the equation above, a and b are the first and second ordinates in the pair of numbers which are provided as each point on the binary file.
    
3. Adding the distances of each of the set of points. 
    
    As the distances of each of the points are calculated, the cumulated value is stored in a single space which is then output at the end of the program.
    
# Conclusion

In this way, the program is able to take advantage of the consistently vaid input to be able to calculate the sum of all the vertices of the points which create a convex 2D shape.