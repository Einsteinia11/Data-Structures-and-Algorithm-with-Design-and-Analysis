#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &vc) {
	for (auto i : vc) {
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	vector <int> vc{20,30,40,10};

	make_heap(vc.begin(), vc.end());
cout << "Initial Heap: ";
	print(vc);

	vc.push_back(50);
	cout << "Heap just after push_back(): ";
	print(vc);
	push_heap(vc.begin(), vc.end());
cout << "Heap after push_heap(): ";
	print(vc);

	return 0;
}
