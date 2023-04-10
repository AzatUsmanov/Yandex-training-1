#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector <long long> vec;

long long GetSum(int d1, int d2, vec& sum1, vec& sum2) {
	if (d2 > d1) {
		return sum1[d2] - sum1[d1];
	}
	else {
		return sum2[d1] - sum2[d2];
	}
}

int main()
{
	ofstream cout("output.txt");
	vec x, y, sum1, sum2, ans;
	long long n, d1, d2, zero = 0;
	cin >> n;
	x.resize(n);
	y.resize(n);
	sum1.resize(n);
	sum2.resize(n);
	for (size_t i = 0; i < size_t(n); i++)
	{
		cin >> x[i] >> y[i];
	}
	for (size_t i = 1; i < n; i++)
	{
		sum1[i] = sum1[i - 1] + max(y[i] - y[i - 1], zero);
		sum2[i] = sum2[i - 1] + abs(min(y[i] - y[i - 1], zero));
	}
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> d1 >> d2;
		cout << GetSum(d1-1, d2-1, sum1, sum2) << endl;
	}
}