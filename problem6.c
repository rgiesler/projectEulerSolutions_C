#include <stdio.h>

/*	The sum of the squares of the first ten natural numbers is,

		1^2 + 2^2 + ... + 10^2 = 385

	The square of the sum of the first ten natural numbers is,

		(1 + 2 + ... + 10)^2 = 55^2 = 3025

	Hence the difference between the sum of the squares of the first ten natural
	numbers and the square of the sum is 3025 − 385 = 2640.

	Find the difference between the sum of the squares of the first one hundred 
	natural numbers and the square of the sum.
*/

#define N 100

/*	See theory below */
int main (int argc, char *argv[])
{
	long sum, sumOfSquares;
	sum = N*(N-1)/2;
	sumOfSquares = (N*(N+1)*(2*N+1))/6;
	printf("Difference: %ld\n", sum*sum-sumOfSquares);
	return 0;
}

/*	Sum of squares (where sum^2 represents sum of squares):
	--------------

	sum^2 = n*(n+1)*(2n+1)/6

	Proof:
	------
	Looking at the differences to find a pattern:
	n		0	1	2	3	4 	5 	6
	n^2 	0	1	4	9	16	25	36
	sum^2 	0	1	5	14	30	55	91
	diff1		1	4	9	16	25	36
	diff2	 		3	5	7	9	11
	diff3				2	2	2	2

	Since when we get to diff3 it is constant, we can say we have an expression 
	of the form:

	an^3 + bn^2 + cn + d

	Now we need to find the constants:
	n 		0		1 			2			3
	sum 	0		1 			5 			14
			d=0		a+b+c=1		8a+4b+3c=5 	27a+9b+3c=14
	4 unknowns, 4 equations, we can solve:
	a = 1/3
	b = 1/2
	c = 1/6
	d = 0

	Giving us:
	sum^2 = (n^3)/3 + (n^2)/2 + (n)/6

	Which is the same as the above equation.
*/

/*	Sum of natural numbers:
	-----------------------

	sum = n*(n+1)/2

	Proof:
	------
	1 + 2 + ... + (n-1) + n = sum
	(1 + 2 + ... + (n-1) + n) + (1 + 2 + ... + (n-1) + n) = 2*sum

	(1 +    2  + ... + (n-1) + n) + 
	(n + (n-1) + ... +    2  + 1) = 2*sum

	Summing the columns, we always sum to n+1, and since there are n terms:

	n*(n+1) = 2*sum
*/

