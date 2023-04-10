#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool Check(long long m, long long x, long long y, long long n) {
	m -= min(x, y);
	if (m < 0) return false;
	return (m / x + m / y + 1) >= n;
}

long long BinSearch2(long long l, long long r, long long x, long long y, long long n) {
	long long m;
	while (l < r) {
		m = (l + r) / 2;
		if (Check(m, x, y, n)) {
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
	long long n, x, y;
	cin >> n >> x >> y;
	cout << BinSearch2(0, n*max(x,y), x, y, n);
}

