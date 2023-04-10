#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool Check(long long m, long long a, long long b, long long t) {
	if (a < 2 * m || b < 2 * m) return false;
	return a * b - (a - 2 * m) * (b - 2 * m) <= t;
}

long long BinSearch(long long l, long long r, long long a, long long b, long long t) {
	long long m;
	while (l < r) {
		m = (l + r + 1) / 2;
		if (Check(m, a, b, t)) {
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
	long long a, b, t;
	cin >> a >> b >> t;
	cout << BinSearch(0, max(a,b), a, b, t);
}

