# My Algorithm (steps to solve the problem)

### Problem Abstraction
This problem is a coverter that is meant to convert units of Temperature or Distance. When it comes to the conversions themselves, they have simple mathematical formulas which can be used to evaluate the conversions from one unit to another. 

The caveat here though, is that the user input is not assumed to be cleaned all the time, which is why our program must also contain several input validation functions. 

In order to better break down the problem, below is a breakdown of the structure of the program. 

## Program Structure
1. Importing header files
2. Functions for Input Validation
3. Functions for converting Temperatures
4. Functions for converting Distances
5. Main Function

#### Functions for Input Validation
As defined in the prompt, there are 3 main types of input validation that the algorithm must be able to handle : 
- Format Errors : This error handles values where there is an unexpected data type used during input.
- Unknown Converstions : This error is used to handle the user input specifically for the first input which is used to evaluate which type of conversion to do : Temperature / Distance. 
- Invalid Unit Error : This error is used to handle user input where exact units are mentioned. It checks against the available optins as well as the accepted cases for the inputs.

A key aspect of the above error is that, each time any one of them is flagged, they immediately output a statement and end the program. 

#### Functions for converting Temperatures
Here, there are 3 different functins that can be used to convert any given unit from a value to the unit mentioned by the function. These function would contain a method to convert the input value depending on the type of unit that is input. 
1. Conversion to Fahrenheit
2. Conversion to Celsius
3. Conversion to Kelvin 

#### Functions for converting Distances
As mentioned in the functions for converting Temperatures, here the program would contain a method to convert to each of the respective options from one unit to another, until all the input validations pass : 
1. Convert to Inches
2. Convert to Feet
3. Convert to Yards
4. Convert to Miles


#### Main Function
Here, the program would start with some setup output after which some input will be taken and they will each be validated based on their nature as described above. 
If all the input validation pass, the conversion functions would be used to find the values for the output.

# Differences
The only change I made was to simplify some of my functions that involved calculation of the changing units.