#include <bits/stdc++.h>
using namespace std;

void print(vector<int>& vc)
{
	for (auto i : vc) {
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> vc{ 40, 10, 20, 50, 30 };

	make_heap(vc.begin(), vc.end());
	cout << "Initial Heap: ";
	print(vc);
	pop_heap(vc.begin(), vc.end());
	cout << "Heap after pop_heap(): ";
	print(vc);
	vc.pop_back();
	cout << "Heap after pop_back(): ";
	print(vc);

	return 0;
}
