#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
	ifstream fin("input.txt");
	long long k, t = 0, ans = 0, f = 0, zero = 0;
	char c;
	vector<char> a, temp;
	fin >> k;
	while (fin >> c) {
		a.push_back(c);
	}
	for (long long i = 0; i < k; i++)
	{
		temp.push_back(a[i]);
	}
	for (long long i = k; i < a.size(); i++)
	{
		for (long long j = i + t; j < a.size(); j++)
		{
			if (temp[t % k] == a[j]) {
				t++;
			}
			else break;
		}
		temp.push_back(a[i]);
		temp.erase(temp.begin());
		ans += t;
		t = max(t - 1, zero);
	}
	cout << ans;
}
