#include <stdio.h>

/*	If we list all the natural numbers below 10 that are multiples of 3 or 5, we
	get 3, 5, 6 and 9. The sum of these multiples is 23.

	Find the sum of all the multiples of 3 or 5 below 1000.
*/

int sumDivisbleBy(int k, int limit);

/*	See theoretical explination below	*/
int main(int args, char *argv[])
{
	int sum = sumDivisbleBy(3, 999) + sumDivisbleBy(5, 999) 
				- sumDivisbleBy(15, 999);

	printf("Sum: %d\n", sum);

	return 0;
}

/*	See theoretical explination below. Find the sum of all the multiples of k
	in the interval [0, limit]	*/	
int sumDivisbleBy(int k, int limit)
{
	int N = limit/k;
	return k*(N*(N+1)/2);
}

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

/*	For the example of 3:
	
		3 + 6 + 9 + ... + 999 = 3*(1 + 2 + 3 + ... + 333)

	so we can use the sum of natural numbers to find the sum of the multiple of
	k up to N (where N is the integer division n/k, in the above example 333) is

		k*(N*(N+1)/2)

	which should be quite straight forward to see from the example of 3.
*/

/*	We can use the above knowledge and use:

		sum = sumDivisibleBy3 + sumDivisibleBy5

	except that numbers that are multiples of 3 and 5 are repeated. Since all
	multiples of 15 are multiples of both 3 and 5, we can say:

		sum = sumDivisibleBy3 + sumDivisibleBy5 - sumDivisibleBy15
*/