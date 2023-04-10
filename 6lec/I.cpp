#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

bool Check(long long m, long long k, long long c, vector<long long> a) {
	long long brig = 0;
	for (size_t i = 0; i < a.size() - c + 1; i++)
	{
		if (a[i+c-1] - a[i] <= m) {
			brig++;
			i += c - 1;
		}
	}
	return brig >= k;
}

long long BinSearch(long long l, long long r, long long k, long long c, vector<long long>& a) {
	long long m;
	while (l < r) {
		m = (l + r) / 2;
		if (Check(m, k, c, a)) {
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
	long long n, r, c, Max;
	cin >> n >> r >> c;
	vector<long long> l(n);
	for (size_t i = 0; i < n; i++)
	{
		cin >> l[i];
		Max = max(Max, l[i]);
	}
	sort(l.begin(), l.end());
	cout << BinSearch(0, Max, r, c, l);
}