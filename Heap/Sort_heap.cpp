#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> v1 = { 20, 30, 40, 25, 15 };
	make_heap(v1.begin(), v1.end());
	cout << "The heap elements are: ";
	for (int& x : v1)
		cout << x << " ";
	cout << endl;
	sort_heap(v1.begin(), v1.end());
	cout << "The heap elements after sorting are: ";
	for (int& x : v1)
		cout << x << " ";

	return 0;
}
