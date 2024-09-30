all: Field

Field: Field.c
	gcc Field.c -g -o Field -lm

run: Field
	./Field
