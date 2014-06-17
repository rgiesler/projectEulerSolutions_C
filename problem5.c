#include <stdio.h>

/*	2520 is the smallest number that can be divided by each of the numbers from 
	1 to 10 without any remainder.

	What is the smallest positive number that is evenly divisible by all of the 
	numbers from 1 to 20?
*/

int isDivisible(const int n, int limit);

int main (int argc, char *argv[])
{
	// We know that we need to start at 2520, and go up in multiples of twenty
	// since 2520 is divisible by 20
	int i=2520;

	while(!isDivisible(i,20)) {i+=20;}

	printf("Smallest divisible number: %d\n", i);
	return 0;
}

int isDivisible(const int n, int limit)
{
	int i;
	for(i = 2; i <= limit; i++)
		if(n%i != 0) return 0;
	return 1;
}