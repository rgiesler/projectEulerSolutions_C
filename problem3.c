#include <stdio.h>

/*	The prime factors of 13195 are 5, 7, 13 and 29.

	What is the largest prime factor of the number 600851475143 ?
*/

/*	See theoretical description below	*/
int main(int argc, char *argv[])
{
	long long n = 600851475143;
	long long currentPrime = 1;
	while (n > 1) {
		currentPrime++;
		while(n%currentPrime ==0)
			n/=currentPrime;
	}
	printf("Largest prime factor: %lld\n", currentPrime);
	return 0;
}

/*	For this problem we use the fact that any integer can be reduced to its 
	prime factors. So we go through each prime number, dividing the factor out
	of the number, until we end up with 1. Then the last factor that we tried
	will be the largest prime factor.

	The interesting thing is that we don't need to actually find the primes, as
	once we've divided out all the 2's, then 4 won't evenly divide. So we can
	just go through all the numbers, and not have to do the computationally
	difficult task of finding all the prime numbers.
*/