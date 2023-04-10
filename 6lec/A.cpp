#include <iostream>
#include <vector>
using namespace std;

int BinSearch(vector<int>& a, int x) {
	int l = 0, r = a.size() - 1, m;
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
	vector<int> a(n), b(k);
	for (size_t i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (size_t i = 0; i < k; i++)
	{
		cin >> p;
		if (a[BinSearch(a,p)] == p) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}

