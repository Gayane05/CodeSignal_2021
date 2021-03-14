#include <iostream>
#include <vector>
#include <algorithm>

//Some people are standing in a row in a park.There are trees between them which cannot be moved.
//Your task is to rearrange the people by their heights in a non - descending order without moving 
//the trees.People can be very tall!

//Example
//
//For a = [-1, 150, 190, 170, -1, -1, 160, 180], the output should be
//sortByHeight(a) = [-1, 150, 160, 170, -1, -1, 180, 190].
//
//If a[i] = -1, then the ith position is occupied by a tree.Otherwise a[i] is the height of a person 
//standing in the ith position.
//
//Guaranteed constraints :
//1 ≤ a.length ≤ 1000,
//-1 ≤ a[i] ≤ 1000.

std::vector<int> sortByHeight(std::vector<int> a)
{
	// By me: With Selection sort
	// Solution is without using additional memory
	int l = 0;
	for (int i = 1; i < a.size(); ++i)
	{
		if (a[i] != -1)
		{
			for (int j = i; j > 0; --j)
			{
				while (j >= 0 && a[j] == -1)
				{
					--j;
				}
				l = j - 1;
				while (l >= 0 && a[l] == -1)
				{
					--l;
				}
				if (l >= 0 && a[j] < a[l])
				{
					std::swap(a[j], a[l]);
				}
			}
		}
	}

	// NBME - With using additional memory.
	/*std::vector<int> tmp = a;
	std::sort(tmp.begin(), tmp.end());

	int idx = 0;
	for (int i : tmp) 
	{
		if (i >= 0) 
		{
			while (a[idx] == -1)
			{
				++idx;
			}
			a[idx] = i;
			++idx;
		}
	}*/

	return a;
}

int main()
{
	std::vector<int> nums{ -1, 150, 190, 170, -1, -1, 160, 180 };
	// 23, 54, -1, 43, 1, -1, -1, 77, -1, -1, -1, 3
	sortByHeight(nums);

	return 0;
}
