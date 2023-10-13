#include <bits/stdc++.h>
using namespace std;
int main()
{

	vector<int> v1 = { 40, 30, 25, 35, 15 };
	vector<int>::iterator it1;
	is_heap(v1.begin(), v1.end())
		? cout << "The container is heap "
		: cout << "The container is not heap"; // ternary operator
	cout << endl;
	auto it = is_heap_until(v1.begin(), v1.end());
	cout << "The heap elements in container are : ";
	for (it1 = v1.begin(); it1 != it; it1++)
		cout << *it1 << " ";

	return 0;
}
