#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <math.h>
using namespace std;

typedef unordered_set<long long> set;
typedef pair<long, long> pr;

void func(vector<pair<pr, pr>>& a, set& m, int n, bool& x, pr& start, long& time) {
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a[i].second.first == 1) {
			m.insert(a[i].second.second);
		}
		else {
			m.erase(a[i].second.second);
		}
		if (!x && m.size() == n) {
			x = true;
			start = a[i].first;
		}
		if (x && m.size() < n) {
			x = false;
			if (start.first > a[i].first.first) {
				start.first -= 24;
			}
			else if (start.first == a[i].first.first && start.second >= a[i].first.second) {
				start.first -= 24;
			}
			time += 60 * (a[i].first.first - start.first) + (a[i].first.second - start.second);
		}
	}
}

int main()
{
	long n, time = 0;
	cin >> n;
	vector<pair<pr, pr>> a(2*n);
	set s, m;
	bool x = false;
	pr start(0,0);
	for (size_t i = 0; i < 2*n; i++)
	{
		cin >> a[i].first.first >> a[i].first.second;
		a[i].second.first = 1;
		a[i].second.second = i;
		a[i + 1].second.second = i;
		i++;
		a[i].second.first = -1;
		cin >> a[i].first.first >> a[i].first.second;
	}
	sort(a.begin(), a.end());
	func(a, m, n, x, start, time);
	time = 0;
	func(a, m, n, x, start, time);
	cout << time;
}


