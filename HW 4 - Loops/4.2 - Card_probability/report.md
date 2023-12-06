# Algorithm (steps to solve the problem)

## Understanding the Problem

This problem is a special card shuffling problem where the probability of drawing out a given number of cards needs to be calculated. The only catch is that since it has to do with cards that are all mutually exclusive, which means that they all have equal probability of occuring. 

But unlike a classic dice spin, the problem is introduced by the unique shuffling structure which has been introduced in this problem. As a result, a unique algorithm can be developed in accordance with the way the cards are shuffled to allow for the computatiion of the probability of drawing the 2 cards. 

The 2 key concepts that will be utilized from the blurb of information above include: 
1. Disjoint Probabilities
2. Shuffling structure

#### 1. Disjoint Probabibilities

This concept conveys that if the probability of an event to happen is A, then B is the probability that the event will not occur. Althogh A + B is always 1. This means that A (a.k.a the probability for something to occur) can be found by sutracting B from 1, thereby giving A. 
This means that by finding the probability of all the situations where the card cannot be drawn can be used to find the probability for the cases where it can. 

#### 2. Shuffling Structure

1. This shuffle, first starts with drawing out N cards from the deck
2. Next a Mulligan is performed wherein between 0 and X cards are taken out of the cards currently in our hand and stored in a separate mulligan pile. if A cards were stored in the mulligan pile, then A more cards are drawn from the deck. 
3. Finally, The mulligan pile is shuffled back into the deck and after this happens the user continues to draw one more card per turn. 

## Program Structure
1. Function to calculate the probabilties
2. Function to calculate the final 1 - B = A probability
3. Function to determine the inputs to calulate the probability
4. Main function

### Function to declare probabilties 

Since, we know that these are disjoint events but the user may require the calculation of cases where more than 1 card is asked to drawn out from the pile, muliganed or drawn one at a time, the technique described below will be used to calulate the probability of not being able to draw the desired card at any give stage of the shuffle. 

```Probability = number of cards not desired - 1 / number of cards not desired```
The above number would be multipled by subtracting 1 from both the numerator and denominator, and this multiplication cycle would continue for the number of cards that are to drawn or mulliganed depending on the user input.

### Function to calculate the 1 - B = A 

This function will be called to calulate the final probability of the cards to be picked and it will essentially just ass the probability values from the 3 previous draws and mulligans to compute the value and output it.

### Function to determing the inputs to calculate the probability

Since this program must be able to maintain a certail order while calculating the probabilties this function will be placed below the other 2 functions since it would be the only layer above the main function and be responsible to call the probability calculation function which was described at the top. 

### The Main function 

This function will basically get the inputs and make a call to the function described previously to do all the heavylifting.

# Differences

There were absolutely no changes that I made to the program.