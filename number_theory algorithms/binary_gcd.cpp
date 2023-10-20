#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	if (a == b)
		return a;

	if (a == 0)
		return b;
	if (b == 0)
		return a;

	if (~a & 1)
	{
		if (b & 1)
			return gcd(a >> 1, b);
		else
			return gcd(a >> 1, b >> 1) << 1;
	}

	if (~b & 1)
		return gcd(a, b >> 1);

	if (a > b)
		return gcd((a - b) >> 1, b);

	return gcd((b - a) >> 1, a);
}

int main()
{
	int a = 34, b = 17;
	printf("Gcd of given numbers is %d\n", gcd(a, b));
	return 0;
}
