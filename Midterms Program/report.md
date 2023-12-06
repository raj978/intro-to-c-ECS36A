# Algorithm (steps to solve the problem)
# My Algorithm (steps to solve the problem)

The main function of this program is to play the game of ConnectN, where the user inputs 3 values namely: 
1. Rows
2. Columns
3. Length of the connection to win

Once the program recieves the input, it creates a playing board and displays its visualization to the user; following which the user throws prompts for the Player 1 to play their first move, then Player 2 and so on. This process keeps repeating until the program detects a winner or no connections are reached and the players run out space to play. In this case the program returns a tie as the result.

In order to make use of the input and be able to produce the correct output of the winner, ties, or invalid input; the following steps must be carried out.

## Playing the game
- get user input from player A and funnel it for input validation. 
- if no exceptions are encoutered, funnel the input to set up the updated board.
- repeat the 2 steps above for getting, validating, and setting up the updated board depending on Player B's input.

## Input Validation

---

### Validation for arguments at start of the Program (y/n) - Parent
- check that there are 3 input integers
- throw an error if there are not 3 inputs. 
- check that the third input is greater than 0

### Looking for empty space in a given column (no return value) - child
- recive user input, and going downwards from R-1 index, where R is the total number of rows on the board; on column C+1, where C is the column input by the user.
    - for the first '*' encountered replace its value with the player's respective piece.
- if no empty space is found, then indicate a failed attempt at finding an empty space in the given column.

### Validation for user input argument for piece placement (y/n) - Parent
- check that the piece's target column is not already full, by getting input .
- if its full, prompt the user for another input until a valid value is obtained.

## Setting up the Board

---

### Initial Setup and program start (no return value)
- take in inputs on the number of rows and columns from the user. 
- create a template that fills a grid of '*' with row and column labels. 
 
### Updating the board and pieces on it (no return value)
- take validated input from the user for the column location of the piece on the board
- traverse to the given coordinates, R-1 where R is the total number of rows on the board; on column C+1, where C is the column input by the user. 
- then set the value at the coordinates equal to the given player's piece.
- re-display all the values on the board.

## Winning the game

---

### Checking for a vertical connection of N pieces (y/n)
- after the user inputs a validated value for the column to place their piece, the board updates its values with the corrected piece in its new position. 
- it then checks all the rows of a each column on the baord for consecutive pieces that equal to the N connections or if N > rows of the board, the number of consecutive pieces are equal to the number of rows in the board.
    - it resets the count each time any of the pieces are not consecutive.

### Checking for Horizontal connection of N pieces (y/n)
- after the user inputs a validated value for the column to place their piece, the board updates its values with the corrected piece in its new position. 
- it then checks all the columns of each of the rows in the board for consecutive pieces that equal to the N connections or if N > columns of the board, the number of consecutive pieces are equal to the number of columns in the board.
    - it resets the count each time any of the pieces are not consecutive.
    
### Checking if the board is a square (y/n) - child
- this is to check if the board has the same number of rows and columns. 
    - in this case, if the number of consecutive pieces required to win is greater than the diagonal length ( which is equal to the size of the rows or the columns), then the function is instructed to look for slanted connections.
- otherwise, if the condition is not met, the program doesn't loop for any slanted connections at all.

### Caluculating the starting/ending point according to size to win from left corner (no value is returned) - child
- check that column size is less than row size, then the starting point for the row would be at the bottom-left corner R - 1 - x, where x would represent the size to win.
    - starting at that point, it would decrement 1 from each x and y coordinate until the end of the board is reached, this value is stored and the starting and ending point is returned.
    - the function would ideally be called again, when the starting and ending point of the row above it or beside it is to be computed.
    - this approach would only work if x is less than or equal to the smallest board dimension.
- check that the row size is less than the column size in which case the start point would be at the bottom-right corner. 

    
### Checking for slanted connections from the top-left corner (y/n) - parent
- starting at postion [0][1], the programs increases both the x and the y coordinate on the board to check if there are any consecutive pieces. 
- check the value is equal to the N connections or if N > columns/rows and verify the board is a square. In this case, the number of consecutive pieces are equal to the diagnonal length of the board - then it counts the input as valid.
    - it resets the value each time pieces are not consecutive.
    - if the board is not a square, then the diagonal trick doesn't work.
- in the event that the board is not a square:
    - it only looks for diagonals if the nunmber of consecutive pieces needed to win is less than or eqal to the size of the smallest row/column.
    - check that the condition is met, it calculates a starting point and end point with diagnonal lengths equal to the size of number of connections required to win.
    - check that the number of connections to win is greater than the size of the diagonal (which is the same as the size of the smallest dimension on the board).
        - in this case, the program then checks for the starting point 
        
    
### Checking for slanted connections from the top-right corner of the board (y/n) - parent
- here, starting at [R][C] where R and C are the numbers of rows and columns as input by the user, the program decreases the x and y coordinate each time to check for consecutive pieces.
- if the value is equal to the N connections or if N is greater than columns/rows and if the board is a square, and the number of consecutive pieces are equal to the diagnonal lenght of the board - then it counts the input as valid.
    - it resets the value each time pieces are not consecutive.
    - if the board is not a square, then the diagonal trick doesn't work.
- in the event that the board is not a square:
    - it only looks for diagonals if the nunmber of consecutive pieces needed to win is less than or eqal to the size of the smallest row/column.

# Differences

There were quite a few changes that I had to make during the implementation of this particular program. 

1. sizing of the whole board was adding 1 more element to both the row and column to accodmodate for the bordering x and y axis that is output. 
2. My technnique to solve for the slant cases was much more simplified as I was able to use a structure similar to that used in the vertical and horizontal connection. 
    - I just added another loop that traverses in the positive and negative slopre direction. 
3.  I had to make by far the most number of changes in the input verification for the column, which needed to take a whole line of input while ignoring any whitespace characters.
4. The computation for a tie game was also a bit different, instead of making an exlusive function it became the default outout in case that all other strategies to win were futile.