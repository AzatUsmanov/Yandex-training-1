#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int Hash(vector<char> x) {
	return (((x[0] + x[1]) % 17) * 7) % 163;
}

struct set {
	set() {
		a.resize(163);
	}
	vector<vector<vector<char>>> a;
	void add(vector<char> x) {
		if (find(x)) {
			return;
		}
		int hash = Hash(x);
		a[hash].push_back(x);
	}
	bool find(vector<char> x) {
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
		for (int i = 0; i < a.size(); i++)
		{
			count += a[i].size();
		}
		return count;
	}
};


int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	string line, line2;
	set m;
	int count = 0;
	getline(fin, line);
	getline(fin, line2);
	for (size_t i = 1; i < line2.size(); i++)
	{
		m.add(vector<char>{line2[i-1], line2[i]});
	}

	for (size_t i = 1; i < line.size(); i++)
	{
		if (m.find(vector<char>{line[i - 1], line[i]})) {
			count++;
		}
	}

	fout << count;
}

