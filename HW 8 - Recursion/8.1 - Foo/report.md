# Algorithm (steps to solve the problem)# My Algorithm (steps to solve the problem)

The purpose of this function is to use the functionality of a special programming construct to find the final value of foo. 

# Defining the base cases
In this program, there are certai function calls which have been given pre assigned values. These values are : 
1. foo(0) = 3
2. foo(1) = 6
3. foo(2) = 2
4. foo(3) = 7

Any value higher than 3, input to the function foo, would break down in the following manner : 
foo(N) = foo(N - 1) + foo(N - 2) + foo(N - 3) - foo(N - 4) + 1

This call will in turn keep triggering the function call until the value inside the function is equal to one of the base cases which is able to return a usable value. 

# Conclusion

In this way, the program is able to use the base cases as well a designed process to deal with an argument that is greater than 3.

# Differences

The only difference between my description was in the adddion of a new pointer array to store the integer values for any of the computations which had already been completed. As a result, the program was able to take in large inputs and produce an output that had a relatively small runtime.