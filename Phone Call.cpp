#include <iostream>

// Some phone usage rate may be described as follows :
// 
// first minute of a call costs min1 cents,
// each minute from the 2nd up to 10th(inclusive) costs min2_10 cents
// each minute after 10th costs min11 cents.
// You have s cents on your account before the call.What is the duration of the longest call(in minutes rounded down to the nearest integer) you can have ?
// 
// Example
// 
// For min1 = 3, min2_10 = 1, min11 = 2, and s = 20, the output should be
// phoneCall(min1, min2_10, min11, s) = 14.

int phoneCall(int min1, int min2_10, int min11, int s)
{
	// Version 1
	/*int minutes_to_talk = 0;
	bool is_less_than_10min = false;

	if (s >= min1)
	{
		s -= min1;
		minutes_to_talk += 1;

		if (s > min2_10)
		{

			if (min2_10 * 9 < s)
			{
				s -= min2_10 * 9;
				minutes_to_talk += 9;
			}
			else
			{
				int i = 1;

				while (i < 10)
				{
					s /= min2_10;
					minutes_to_talk += 1;
					if (s >= min2_10)
					{
						++i;
					}
					else
					{
						is_less_than_10min = true;
						break;
					}
				}
			}
			
			if (!is_less_than_10min && s / min11 > 0)
			{
				minutes_to_talk += s / min11;
			}
		}
	}
	return minutes_to_talk;*/


	// Version 2
	int minutes_to_talk = 0;

	if (s < min1)
	{
		return 0;
	}
	else
	{
		minutes_to_talk += 1;
		s -= min1;
		if (s >= min2_10 * 9)
		{
			minutes_to_talk += 9;
			s -= min2_10 * 9;
			if (s >= min11)
			{
				minutes_to_talk += s / min11;
			}
		}
		else
		{
			minutes_to_talk += s / min2_10;
		}
	}

	return minutes_to_talk;


	// Version 3
	// NTBM
	/*if (s < min1) {
		return 0;
	}
	if (s < min1 + 9 * min2_10) {
		return 1 + (s - min1) / min2_10;
	}
	return 10 + (s - min1 - 9 * min2_10) / min11;*/
}


int main()
{
    
	phoneCall(1, 2, 1, 6);

	return 0;
}