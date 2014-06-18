#include <stdio.h>

/*	A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

		a^2 + b^2 = c^2

	For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

	There exists exactly one Pythagorean triplet for which a + b + c = 1000.
	Find the product abc.
*/

#define LIMIT 1000

/*	See the theory for upper limits below	*/
int main(int argc, char *argv[])
{
	int a, b, c, found;

	for(a = 1; a < LIMIT/3; a++) {
		for(b = 1; b < LIMIT/2; b++) {
			c = LIMIT - a - b;
			if (a*a + b*b == c*c) {
				found = 1;
				break;
			}
		}
		if(found) break;
	}

	printf("The product is: %d\n", a*b*c);
	return 0;
}

/*	The upper limits of a and b of a pythagorean triplets with regards to the
	sum or perimeter s is:

		a < s/3
		b < s/2

	Proof:
	------
	If a = b, then:

		2*(a^2) = c^2
		sqrt(2)*a = c

	Since a, b, and c are integers, there exists no a, b, c such that a = b.
	We know as a property of pythagoras triplets that c > a, and that c > b.
	Since a != b, and a and b can be switched around, we will define a < b, and
	then the following will always be true for all pythagorean triplets:

		a < b < c

	If we add (a+b) to the inequality:

		2a + b < a + 2b < a + b + c

	We will define the perimeter or sum s as:

		s = a + b + c

	Using the left and right inequalities, we get:

		2a + b < s

	Since a < b, if we substitute a into b, we will only make the left side 
	smaller, which will mean that the inequality will stay true:

		3a < s
		a < s/3

	We can do a similar thing for b. Taking the two right inequalities this time

		a + 2b < s

	If we remove a from the left hand side, it will only make the left hand side
	smaller (since a cannot be negative)

		2b < s
		b < s/2
*/