# Algorithm (steps to solve the problem)
This problem involved calculating the multiplication of 2 complex numbers. 

## Multiplying the Complex numbers

Assuming that all the input enter by the user is valid, and that the program doesn't have to compute whether or not the values which have been input are correct. 

To evaluate the multiplication, the algorithm must compute the following : 

```(a + bi) (c + di) = (ac - bd) + (ad + bc)i```

Although, we see that the input we get is in a combined form which includes the values a, b and i in the same sentence. Hence our first step would be to separate the inputs.

### Separating the input values and storing them

In order to make sure that the program is able to correctly calculate the value obtained from the multiplication, our algoeithm uses the positions of the characters a and b in a + bi to store them separately so they can be arithmentically operated on. 

### Calculating the resulting value of multiplicaton

Now that the program has obtained the input, it simply calculates the operation ``` ( a*c - b*d) to calculate the real number and then (a * d + b * c) to calculate the imaginary part of the answer.

### Displaying the Answer

Finally, after we've been able to calculate the answer, all that is left is displaying the output.

# Differences

I made one key change in my program as a result of which I was able to correctly execute my algorithm and solve the problem. 

### Using the write input structure

Owing to the fact that the user may input the compblex numbers in ways such as a+bi or a + b i. The algorithm must be able to read them in the same way and produce precise results each time. By changing the input sturcture to include whitespaces, this issue was resolved.