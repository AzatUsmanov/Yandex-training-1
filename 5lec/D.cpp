#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector <long long> a;
	long long n, k, ans = 0;
	cin >> n >> k;
	a.resize(n);
	for (size_t i = 0; i < size_t(n); i++)
	{
		cin >> a[i];
	}
	size_t i = 0, j = 0;
	while (i != a.size() && j != a.size())
	{
		if (a[i] + k < a[j] && i < a.size()) {
			ans += a.size() - j;
			i++;
		}
		else if (j < a.size()) {
			j++;
		}
	}
	cout << ans;
}