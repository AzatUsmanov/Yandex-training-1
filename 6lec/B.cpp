#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int BinSearch(vector<int>& a, int x) {
	int l = 0, r = a.size()-1, m;
	while (l < r) {
		m = (l + r + 1) / 2;
		if (a[m] <= x) {
			l = m;
		}
		else {
			r = m - 1;
		}
	}
	return l;
}

int BinSearch2(vector<int>& a, int x) {
	int l = 0, r = a.size()-1, m;
	while (l < r) {
		m = (l + r) / 2;
		if (a[m] >= x) {
			r = m;
		}
		else {
			l = m + 1;
		}
	}
	return l;
}

int main()
{
	int n, k, p;
	cin >> n >> k;
	vector<int> a(n);
	for (size_t i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (size_t i = 0; i < k; i++)
	{
		cin >> p;
		int one = a[BinSearch2(a, p)];
		int two = a[BinSearch(a, p)];
		if (abs(one - p) < abs(two - p)) {
			cout << one << endl;
		}
		else if (abs(one - p) > abs(two - p)) {
			cout << two << endl;
		}
		else {
			cout << min(one, two) << endl;
		}
	}
}

