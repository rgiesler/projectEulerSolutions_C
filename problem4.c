#include <stdio.h>

/*	A palindromic number reads the same both ways. The largest palindrome made 
	from the product of two 2-digit numbers is 9009 = 91 × 99.

	Find the largest palindrome made from the product of two 3-digit numbers.
*/

int reverse_int (int num, const int k);
int isIntMultiple (const int min1, const int max1, const int min2, 
	const int max2, int num);

int main(int argc, char *argv[])
{
	/*	Highest possible number is 999*999 = 998001, so only need to check up to
		then. We will create palindromes then check, as it is easier than doing
		it the other way around (computationally easier)
	*/
	int i = 0, palin = 0, max = 0;
	while(palin <= 998001) {
		palin = i*1000 + reverse_int(i, 3);
		if (isIntMultiple(1, 1000, 1, 1000, palin))
			max = palin;
		i++;
	}
	printf("Largest palindrome: %d\n", max);
	return 0;
}

/*	Reverses the order of the digits in the int, with padding to make k digits
*/
int reverse_int (int num, const int k)
{
	int reverse = 0, i;
	for(i = 0; i < k; i++) {
		reverse = reverse * 10 + num%10;
		num /= 10;
	}
	return reverse;
}

/*	Checks to see if num is an integer of i1 and i2, where i1 is in [min1,max1)
	and i2 is in [min2,max2)	*/
int isIntMultiple (const int min1, const int max1, const int min2, 
	const int max2, int num)
{
	int i, i2;
	for (i = min1; i < max1 && i < num; i++) {
		if (num%i == 0) {
			i2 = num/i;
			if(i2 >= min2 && i2 < max2)
				return 1;
		}
	}
	return 0;
}