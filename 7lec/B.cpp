#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	long long n, m;
	cin >> n >> m;
	vector <pair<long, pair<char, long>>> a;
	vector<long>ans(m);
    long x, y;
    long count = 0;
	for (size_t i = 0; i < n; i++)
	{
		cin >> x >> y;
		a.push_back(pair<long, pair<char, long>>(min(x, y), pair<char, long>(-1, i)));
		a.push_back(pair<long, pair<char, long>>(max(x, y), pair<char, long>(1, i)));
	}
	for (size_t i = 0; i < m; i++)
	{
		cin >> x;
		a.push_back(pair<long, pair<char, long>>(x, pair<char, long>(0, i)));
	}
	sort(a.begin(), a.end());
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a[i].second.first == 0) {
			ans[a[i].second.second] = count;
		}
		count -= long(a[i].second.first);
	}
	for (size_t i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
}