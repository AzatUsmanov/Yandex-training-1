#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct set {
	vector<vector<int>> a;

	set(int n) {
		a.resize(n);
	}

	bool Del(int s) {
		int hash = Hash(s);
		for (size_t i = 0; i < a[hash].size(); i++)
		{
			if (a[hash][i] == s) {
				a[hash][i] = -1;
				return true;
			}
		}
		return false;
	}

	int Hash(int s) {
		return (s * s % 1719 + s % 333) % a.size();
	}

	bool Find(int s) {
		int hash = Hash(s);
		for (size_t i = 0; i < a[hash].size(); i++)
		{
			if (a[hash][i] == s) {
				return true;
			}
		}
		return false;
	}

	void Add(int s) {
		int hash = Hash(s);
		if (!Find(s)) {
			a[hash].push_back(s);
		}
	}

	vector<int> GetVec() {
		vector<int> ans;
		for (size_t i = 0; i < a.size(); i++)
		{
			for (size_t j = 0; j < a[i].size(); j++)
			{
				if (a[i][j] != -1) {
					ans.push_back(a[i][j]);
				}
			}
		}
		return ans;
	}
};

void out(vector<int> vec) {
	cout << vec.size() << endl;
	for (size_t i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}

int main()
{
	int n, m, temp;
	cin >> n >> m;
	set a(10 * n), b(10 * m), c(10 * m);

	for (size_t i = 0; i < n; i++)
	{
		cin >> temp;
		a.Add(temp);
	}

	for (size_t i = 0; i < m; i++)
	{
		cin >> temp;
		if (a.Del(temp)) {
			c.Add(temp);
		}
		else {
			b.Add(temp);
		}
	}

	vector<int> any = a.GetVec();
	vector<int> bory = b.GetVec();
	vector<int> ans = c.GetVec();

	sort(any.begin(), any.end());
	sort(bory.begin(), bory.end());
	sort(ans.begin(), ans.end());

	out(ans);
	out(any);
	out(bory);
}

