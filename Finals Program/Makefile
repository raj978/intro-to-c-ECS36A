# Makefile for main.c, input.c, canvas.c, manipulate.c and file.c

CC = gcc
CFLAGS = -g -Wall -Werror

# List of object files to be generated
OBJ = paint.o input.o features.o file.o manipulate.o canvas.o

# Main target
paint.out: $(OBJ)
	$(CC) $(CFLAGS) -o paint.out $^

input.out: $(OBJ)
	$(CC) $(CFLAGS) -o input.out $^

features.out: $(OBJ)
	$(CC) $(CFLAGS) -o features.out $^

file.out: $(OBJ)
	$(CC) $(CFLAGS) -o file.out $^

manipulate.out: $(OBJ)
	$(CC) $(CFLAGS) -o manipulate.out $^

# Rule to build object files
%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

# Clean rule
clean:
	rm -fr *.o *.out