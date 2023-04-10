#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool Check(long m, long w, long h, long n) {
	long k = m / max(h,w);
	if (k == 0) return false;
	return ceil(double(n) / double(k))*min(h,w) <= m;
}

long BinSearch2(long l, long r, long w, long h, long n) {
	long m;
	while (l < r) {
		m = (l + r) / 2;
		if(Check(m, w,h,n)){
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
	long w, h, n;
	cin >> w >> h >> n;
	cout << BinSearch2(0, n * max(w, h), w, h, n);
}