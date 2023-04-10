#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool Check(long long m, long long k, vector<long long>& a) {
	long long count = 0;
	for (size_t i = 0; i < a.size(); i++)
	{
		count += a[i] / m;
	}
	return count >= k;
}

long long BinSearch(long long l, long long r, long long n, long long k, vector<long long>& a) {
	long long m;
	while (l < r) {
		m = (l + r + 1) / 2;
		if (Check(m, k, a)) {
			l = m;
		}
		else {
			r = m - 1;
		}
	}
	return l;
}

int main()
{
	long long n, k, r;
	cin >> n >> k;
	vector<long long> l(n);
	for (size_t i = 0; i < n; i++)
	{
		cin >> l[i];
		r = max(l[i], r);
	}
	cout << BinSearch(0, r, n, k, l);
}

