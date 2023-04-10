#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <vector>
using namespace std;

struct set {
	vector<vector<pair<string, int>>> a;

	set(int n) {
		a.resize(n);
	}

	int Hash(pair<string, int> s) {
		return (s.first.size()*171 + s.first[s.first.size() - 1]) % s.first.size();
	}

	void AddAll(pair<string, int> s) {
		int hash = Hash(s);
		for (size_t i = 0; i < a[hash].size(); i++)
		{
			if (a[hash][i].first == s.first) {
				a[hash][i].second++;
				return;
			}
		}
		a[hash].push_back(s);
	}

	bool Find(pair<string, int> s) {
		int hash = Hash(s);
		for (size_t i = 0; i < a[hash].size(); i++)
		{
			if (a[hash][i].first == s.first) {
				return true;
			}
		}
		return false;
	}

	bool FindAll(int n, string s) {
		int hash = Hash(pair<string, int>(s,n));
		for (size_t i = 0; i < a[hash].size(); i++)
		{
			if (a[hash][i].first == s && a[hash][i].second == n) {
				return true;
			}
		}
		return false;
	}

	vector<string> GetOne() {
		vector<string> ans;
		for (size_t i = 0; i < a.size(); i++)
		{
			for (size_t j = 0; j < a[i].size(); j++)
			{
				ans.push_back(a[i][j].first);
			}
		}
		return ans;
	}

	void Add(pair<string, int> s) {
		int hash = Hash(s);
		if (!Find(s)) {
			a[hash].push_back(s);
		}
	}
};

void out(vector<string> vec) {
	cout << vec.size() << endl;
	for (size_t i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << endl;
	}
}

int main()
{
	string s;
	int n, k;
	set one(1000), all(100000);
	vector<string> oneVec, allVec;

	cin >> n;
	for (size_t i = 0; i < n-1; i++)
	{
		cin >> k;
		for (size_t i = 0; i < k; i++)
		{
			cin >> s;
			one.Add(pair<string, int>(s,1));
			all.AddAll(pair<string, int>(s, 1));
		}
	}

	cin >> k;
	for (size_t i = 0; i < k; i++)
	{
		cin >> s;
		if (all.FindAll(n-1, s)) {
			allVec.push_back(s);
		}
		one.Add(pair<string, int>(s, 1));
	}

	oneVec = one.GetOne();
	out(allVec);
	out(oneVec);
}

