# Makefile for main.c and mat_multiply.c

CC = gcc
CFLAGS = -g -Wall -Werror

# List of object files to be generated
OBJ = setup.o connectn.o input_val.o play.o win.o

# Main target
connectn.out: $(OBJ)
	$(CC) $(CFLAGS) -o connectn.out $^

setup.out: $(OBJ)
	$(CC) $(CFLAGS) -o setup.out $^

play.out: $(OBJ)
	$(CC) $(CFLAGS) -o play.out $^

win.out: $(OBJ)
	$(CC) $(CFLAGS) -o win.out $^

input_val.out: $(OBJ)
	$(CC) $(CFLAGS) -o input_val.out $^

# Rule to build object files
%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

# Clean rule
clean:
	rm -fr *.o *.out
