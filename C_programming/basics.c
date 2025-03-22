#include <stdio.h>

/**
 * main: create array and slice it
 * Return: Success
 */

int main(int ac, char **av, char **env){
	int my_array[32];
	char my_array_of_arrays[8][16];

	int a = 13;

	a? 12: 14;

	printf("Result of the ternary condition above is %d\n", a);
	printf("My array has been created!\n");

	return (0);
}
