#include <iostream>

//Ticket numbers usually consist of an even number of digits.A ticket number is considered 
//lucky if the sum of the first half of the digits is equal to the sum of the second half.
//
//Given a ticket number n, determine if it's lucky or not.
//
//Example
//
//For n = 1230, the output should be
//isLucky(n) = true;
//For n = 239017, the output should be
//isLucky(n) = false.
//Input / Output
//
//[execution time limit] 0.5 seconds(cpp)
//
//[input] integer n
//
//A ticket number represented as a positive integer with an even number of digits.
//
//Guaranteed constraints :
//10 ≤ n < 106.
//
//	[output] boolean
//
//	true if n is a lucky ticket number, false otherwise.

// Need to understand 
bool isLucky(int n) 
{
	/*int digits = (int)log10(n) + 1;
	int sum1 = 0, sum2 = 0;


	for (int x = 0; n > 0; n /= 10, x++) 
	{
		if (x < digits / 2)
			sum1 += n % 10;
		else
			sum2 += n % 10;
	}

	return sum1 == sum2;*/


	int number = n;
	int digits_count = 0;
	while (number > 0)
	{
		number /= 10;
		digits_count++;
	}

	int half = digits_count / 2;

	int first_half = n / pow(10, half);
	int first_half_sum = 0;

	while (first_half > 0)
	{
		first_half_sum += first_half % 10;
		first_half /= 10;
	}


	int second_half = n % static_cast<int>(pow(10, half));
	int second_half_sum = 0;

	while (second_half > 0)
	{
		second_half_sum += second_half % 10;
		second_half /= 10;
	}

	return first_half_sum == second_half_sum;
}

int main()
{
	isLucky(239017);

	return 0;
}