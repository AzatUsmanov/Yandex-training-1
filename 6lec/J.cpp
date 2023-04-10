#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool Check(int m, vector<int>& b, vector<int>& a, int& t) {
	int l = 0, r = b.size() - 1, mid;
	while (l < r) {
		mid = (l + r + 1) / 2;
		if (a[m] >= b[mid]) {
			l = mid;
		}
		else {
			r = mid - 1;
		}
	}
	t = l;
	//cout << a[m] << " " << t << " " << m <<  endl;
	return (b.size() + a.size()) / 2 - 2 <= m + l;
}

int searh(int m, vector<int>& a, vector<int>& b) {
	int l = 0, r = b.size() - 1, mid;
	while (l < r) {
		mid = (l + r + 1) / 2;
		if (a[m] >= b[mid]) {
			l = mid;
		}
		else {
			r = mid - 1;
		}
	}
	return l;
}

pair<int, int> BinSearch(int l, int r, vector<int>& a, vector<int>& b) {
	int m, t;
	while (l < r) {
		m = (l + r) / 2;

		if (Check(m, b, a, t)) {
			r = m;
		}
		else {
			l = m + 1;
		}
	}
	return pair<int, int>(l, t);
}

bool func(vector<int>& a, vector<int>& b) {
	if (a[a.size() - 1] <= b[0]) {
		cout << a[a.size() - 1] << endl;
		return false;
	}
	else if (b[a.size() - 1] <= a[0]) {
		cout << b[a.size() - 1] << endl;
		return false;
	}
	return true;
}

int main()
{
	int n, l, x;
	cin >> n >> l;
	vector<vector<int>> a(n);
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < l; j++)
		{
			cin >> x;
			a[i].push_back(x);
		}
	}
	for (size_t i = 0; i < a.size(); i++)
	{
		for (size_t j = i + 1; j < a.size(); j++)
		{
			if (func(a[i], a[j])) {
				pair<int, int> one = BinSearch(0, a[i].size() - 1, a[i], a[j]);
				pair<int, int> two = BinSearch(0, a[j].size() - 1, a[j], a[i]);
				one.second = searh(one.first, a[i], a[j]);
				two.second = searh(two.first, a[j], a[i]);
				if (one.first + one.second == (a[i].size() + a[j].size()) / 2 - 2 && a[i][one.first] >= a[j][one.second]) {
					cout << a[i][one.first] << endl;
					//<< " " << one.first << " " << one.second << endl;
				}
				else {
					cout << a[j][two.first] << endl;
					//<< " " << two.first << " " << two.second << endl;
				}
			}
		}
	}
}