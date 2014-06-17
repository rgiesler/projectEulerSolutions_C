#include <stdio.h>

/*	2520 is the smallest number that can be divided by each of the numbers from 
	1 to 10 without any remainder.

	What is the smallest positive number that is evenly divisible by all of the 
	numbers from 1 to 20?
*/

/*	See theoretical description below */
int main (int argc, char *argv[])
{
	int primes[8] = {2, 3, 5, 7, 11, 13, 17, 19};
	int result = 1, i, max, max_old;

	for(i = 0; i < 8; i++) {
		max = max_old = 1;
		while((max *= primes[i]) < 20)
			max_old = max;
		result *= max_old;
	}
	
	printf("Smallest divisible number: %d\n", result);
	return 0;
}



/*	We can solve this problem by finding the prime factors of the numbers,
	so that:

		N = p1^a1 + p2^a2 + ... + pn^an

	where p are the prime numbers, and a how many of each number we need to
	find our final number N.

	This alone, however, is not enough, as N needs to fulfill a specific 
	criteria. We can do this by finding the powers of the primes for each 
	divisor (from 1 to 20), and using the maximum number for a out of all of the
	divisors. This will give us the prime factors of the number divisible from
	1 to 20, and we can multiply those prime factors to get the answer.

	We can go further though. For each a, the value of a is the biggest a so 
	that:

		pn^an <= k

	where k is the maximum number. I'm not sure how to explain it, it seems 
	logical to me, I'll show with the example of 2. 2^4 = 16 is the highest
	possible power below 20, which means that 16 is the number which needs the 
	most 2's, any other number needs less 2's, so the maximum power of 2 that
	we need is 4.
*/