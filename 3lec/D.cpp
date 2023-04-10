#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int Hash(string x) {
	int hash = 0;
	for (size_t i = 0; i < x.size(); i++)
	{
		hash += x[i];
	}
	return hash % 163;
}

struct set {
    set() {
		a.resize(163);
	}
	vector<vector<string>> a;
	void add(string x) {
		if (!find(x)) {
			int hash = Hash(x);
			a[hash].push_back(x);
		}
	}
	bool find(string x) {
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
	set s;
	string str;

	while (fin >> str)
		s.add(str);
	fin.close();

	cout << s.FindCount();
}

