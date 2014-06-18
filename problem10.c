#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*	The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

	Find the sum of all the primes below two million.
*/

#define N 2000000

void sieve(char *nums, int lim);

int main(int argc, char *argv[])
{
	char *nums;
	
	int i;
	long sum = 0;

	nums = (char*)calloc(N, sizeof(char));
	if(nums == NULL) return 1;

	sieve(nums, N);

	for(i = 0; i < N; i++)
		if(!nums[i]) {
			sum +=i;
		}

	printf("Sum: %ld\n", sum);

	free(nums);

	return 0;
}

void sieve(char *nums, int lim)
{
	const int limSqrt = (int)sqrt((double)lim);
	int i, j;

	nums[0] = 1;	// 0 and 1 aren't primes
	nums[1] = 1;

	for(i = 2; i <= limSqrt; i++) 
		if(!nums[i]) 
			for(j = i*2; j < lim; j+=i) 
				nums[j] = 1;
}

/*	Since we know the limit for the prime numbers, we will use a sieve:
	https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

	To find all the prime numbers less than or equal to a given integer n by 
	Eratosthenes' method:

	Create a list of consecutive integers from 2 through n: (2, 3, 4, ..., n).

	Initially, let p equal 2, the first prime number.

	Starting from p, enumerate its multiples by counting to n in increments of 
	p, and mark them in the list (these will be 2p, 3p, 4p, etc.; the p itself 
	should not be marked).

	Find the first number greater than p in the list that is not marked. If 
	there was no such number, stop. Otherwise, let p now equal this new number 
	(which is the next prime), and repeat from step 3.
*/