#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int Hash(int x) {
	if (x < 0) {
		x *= (-1);
	}
	return ((x % 17) * 7) % 163;
}

struct set {
    set() {
		a.resize(163);
	}
	vector<vector<int>> a;
	void add(int x) {
		if (find(x)) {
			return;
		}
		int hash = Hash(x);
		a[hash].push_back(x);
	}
	bool find(int x) {
		int hash = Hash(x);
		for (size_t i = 0; i < a[hash].size(); i++)
		{
			if (a[hash][i] == x) { 
				return true;
			}
		}
		return false;
	}
	int FindCount() {
		int count = 0;
		for (size_t i = 0; i < a.size(); i++)
		{
			count += int(a[i].size());
		}
		return count;
	}
};

vector<int> conv(string line) {
	int x = 0;
	bool hasInts = false, minus = false;
	vector<int> a;
	for (size_t i = 0; i < line.length(); i++)
	{
		if (isdigit(line[i])) {
			hasInts = true;
			x = 10 * x + line[i] - 48;
		}
		else if (line[i] == '-') {
			minus = true;
		}
		else if (hasInts) {
			if (minus) {
				x *= -1;
			}
			a.push_back(x);
			x = 0;
			minus = false;
		}
	}

	return a;
}

bool find(vector<int> a, int x) {
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a[i] == x) {
			return true;
		}
	}
	return false;
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
    string line, line2;
	set m;
	getline(fin, line);
	getline(fin, line2);
	vector<int> a = conv(line + " ");
	vector<int> b = conv(line2 + " ");
	vector<int> ans;
	for (size_t i = 0; i < a.size(); i++)
	{
		m.add(a[i]);
	}
	for (size_t i = 0; i < b.size(); i++)
	{
		if (m.find(b[i])) {
			ans.push_back(b[i]);
		}
	}
	sort(ans.begin(), ans.end());
	for (size_t i = 0; i < ans.size(); i++)
	{
		fout << ans[i] << " ";
	}
    return 0;
}

