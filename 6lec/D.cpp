#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool Check(long long m, long long a, long long b, long long w, long long h, long long n) {
	if ((w / (b + 2 * m)) * (h / (a + 2 * m)) >= n)return true;
	if ((w / (a + 2 * m)) * (h / (b + 2 * m)) >= n)return true;
	return false;

}

long long BinSearch2(long long l, long long r, long long a, long long b, long long w, long long h, long long n) {
	long long m, rmax = 0;
	while (l < r) {
		m = (l + r + 1) / 2;
		if (Check(m, a, b, w, h, n)) {
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
	long long n, a, b, w, h;
	cin >> n >> a >> b >> w >> h;
	cout << BinSearch2(0, max(w, h), a, b, w, h, n);
}

