#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>
using namespace std;

int main()
{
	long long n, d;
	cin >> n >> d;
	vector<pair<int, int>> a(n);
	set<pair<int, int>> tickets;
	vector<int> ans(n);
	int y, p, x;
	for (size_t i = 0; i < n; i++)
	{
		cin >> y;
		a[i] = pair<int, int>(y, i);
	}
	sort(a.begin(), a.end());
	tickets.insert(pair<int,int>(a[0].first, 1));
	ans[a[0].second] = 1;
	for (size_t i = 1; i < a.size(); i++)
	{
		if ((*tickets.begin()).first + d < a[i].first) {
			ans[a[i].second] = (*tickets.begin()).second;
			tickets.erase(tickets.begin());
			tickets.insert(pair<int, int>(a[i].first, ans[a[i].second]));
		}
		else {
			ans[a[i].second] = tickets.size() + 1;
			tickets.insert(pair<int, int>(a[i].first, ans[a[i].second]));
		}
	}

	cout << tickets.size() << endl;
	for (size_t i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
}