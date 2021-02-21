#include <iostream>

//Given an integer n, return the largest number that contains exactly n digits.
//
//Example
//
//For n = 2, the output should be
//largestNumber(n) = 99.

int largestNumber(int n)
{
	int number = 0;

	while (n > 0)
	{
		number += 9 * pow(10, n - 1);
		--n;
	}
	return number;
}


// NBYM
//int largestNumber(int n) {
//	return (int)pow(10, n) - 1;
//}



int main()
{
	largestNumber(3);
	return 0;
}
