#include <stdio.h>
#include <math.h>

/*	The prime factors of 13195 are 5, 7, 13 and 29.

	What is the largest prime factor of the number 600851475143 ?
*/

long long nextPrime(long long n);
int isPrime(long long n);

int main(int argc, char *argv[])
{
	long long n = 600851475143;
	long long currentPrime = 1;
	while (n > 1) {
		currentPrime = nextPrime(currentPrime);
		while(n%currentPrime ==0)
			n/=currentPrime;
	}
	printf("Largest prime factor: %lld\n", currentPrime);
	return 0;
}

long long nextPrime(long long n)
{
	do {
		n++;
	} while(!isPrime(n));
	return n;
}

int isPrime(long long n)
{
	if(n <= 1) return 0;
	if(n%2 == 0) return 0;
	long long i, root = (long long)sqrt((double)n);
	for(i = 3; i <= root; i+=2)
		if(n%i == 0) return 0;
	return 1;
}