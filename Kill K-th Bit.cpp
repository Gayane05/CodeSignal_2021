#include <iostream>

// In order to stop the Mad Coder evil genius you need to decipher the encrypted message 
// he sent to his minions.The message contains several numbers that, when typed into a supercomputer, 
// will launch a missile into the sky blocking out the sun, and making all the people on Earth grumpyand sad.
// 
// You figured out that some numbers have a modified single digit in their binary representation. 
// More specifically, in the given number n the kth bit from the right was initially set to 0, 
// but its current value might be different. It's now up to you to write a function that will change the 
// kth bit of n back to 0.
// 
// Example
// 
// For n = 37 and k = 3, the output should be
// killKthBit(n, k) = 33.
// 
// 37(10) = 100101(2) ~> 100001(2) = 33(10).
// 
// For n = 37 and k = 4, the output should be
// killKthBit(n, k) = 37.
// 
// The 4th bit is 0 already(looks like the Mad Coder forgot to encrypt this number), so the answer is still 37.


int killKthBit(int n, int k) 
{
	// First step: generate mask(1) which must have 1 in kth bit. 
	// For that: a) mask = 1. b) 1 << (k-1) -> k-1 steps shift to left -> 000100
	// Second step: revert mask ~ -> 111011
	// Third step: and number and mask 100101 & 111011 ->  100001
	return n & ~(1 << (k-1));
}

int main()
{
    
	killKthBit(37, 3);
	return 0;
}

