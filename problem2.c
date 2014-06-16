#include <stdio.h>

int main(int argc, char *argv[])
{
	long int first = 1, second = 2, sum = 0, tmp = 0;

	while (second < 4000000) {
		// Every third number will be even, so we only need to find every third
		// number and add them all together

		sum += second;

		// now generate third number, example is for first iteration
		first = first + second;		//first = 3, second = 2
		second = first + second;	//first = 3, second = 5
		tmp = second;				//tmp = 5
		second = first + second;	//first = 3, second = 8
		first = tmp;				//first = 5, second = 8

	}

	printf("Sum: %ld\n", sum);
	return 0;
}