#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool Check(long long m, long long a, long long b, long long c) {
	long double s = 5 * m + 2 * a + 3 * b + 4 * c;
	long double k = m + a + b + c;
	return  s / k >= 3.5;
}

long long BinSearch(long long l, long long r, long long a, long long b, long long c) {
	long long m;
	while (l < r) {
		m = (l + r) / 2;
		if (Check(m, a, b, c)) {
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
	long long a, b, c;
	cin >> a >> b >> c;
	cout << BinSearch(0, a + b + c, a, b, c);
}

