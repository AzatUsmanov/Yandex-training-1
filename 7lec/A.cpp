#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	long long n, m, zero = 0;
	cin >> n >> m;
	vector<pair<long long,long long>> a(m);
	for (size_t i = 0; i < m; i++)
	{
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(), a.end());
	long long count = a[0].second - a[0].first + 1;
	long long Max = a[0].second;
	for (size_t i = 1; i < a.size(); i++)
	{
		if (a[i].first > Max) {
			count += a[i].second - a[i].first + 1;
		}
		else {
			count += max(a[i].second - Max, zero);
		}
		Max = max(Max, a[i].second);
	}
	cout << n - count;
}