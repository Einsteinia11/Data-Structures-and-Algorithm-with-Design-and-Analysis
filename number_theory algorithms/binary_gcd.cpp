#include <bits/stdc++.h> // Include necessary header files
using namespace std;

// Function to calculate the greatest common divisor (GCD) of two numbers using Euclidean algorithm
int gcd(int a, int b) {
    // Base case: if both numbers are equal, the GCD is the number itself
	if (a == b) 
		return a;

    // If one of the numbers is 0, the GCD is the non-zero number
	if (a == 0) 
		return b;
	if (b == 0) 
		return a;

    // If both numbers are even, divide both by 2 and multiply the GCD by 2
	if (~a & 1) {
		if (b & 1)
			return gcd(a >> 1, b);
		else
			return gcd(a >> 1, b >> 1) << 1;
	}

    // If 'a' is even and 'b' is odd, divide 'a' by 2
	if (~b & 1)
		return gcd(a, b >> 1);

    // If 'a' and 'b' are both odd, reduce the larger number by the smaller number
	if (a > b)
		return gcd((a - b) >> 1, b);
	return gcd((b - a) >> 1, a);
}

// Main function
int main() {
	int a = 34, b = 17; // Initialize two integers
	printf("Gcd of given numbers is %d\n", gcd(a, b)); // Print the GCD of the given numbers
	return 0; // Return 0 to indicate successful execution
}
