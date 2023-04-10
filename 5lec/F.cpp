#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	long long n, k, i = 0, j = 0, l, r, sum = 0;
	cin >> n;
	vector <long long> a(n);
	for (size_t i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cin >> n;
	vector<pair<long long, long long>> b(n);
	for (size_t i = 0; i < n; i++)
	{
		cin >> b[i].second >> b[i].first;
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	while (i != a.size()) {
		if (a[i] <= b[j].second && i < a.size()) {
			sum += b[j].first;
			i++;
		}
		else if (j < b.size()) {
			j++;
		}
	}
	cout << sum;
}