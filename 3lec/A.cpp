#include <fstream>
#include <iostream>
#include <vector>
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

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	vector<int> nums;
	int num = 0;
	set a;
	while (fin >> num)
		a.add(num);
	fin.close();
	fout << a.FindCount();
}

