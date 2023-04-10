#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
using namespace std;

typedef vector <long long> vec;

int main()
{
	long long n, k, i = 0, j = 0, l, r, min  = 100000000;
	unordered_map<long long, long long> map;
	cin >> n >> k;
	vec a(n);
	for (size_t i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	while (i != a.size() || j != a.size()) {
		if (map.size() < k && j < a.size()) {
			map[a[j]]++;
			j++;
		}

		if (map.size() == k && i != a.size()) {
			if (j - i < min) {
				min = j - i;
				l = i + 1; r = j;
			}
			i++;
			if (map[a[i - 1]] > 1) {
				map[a[i - 1]]--;
			}
			else {
				map.erase(a[i - 1]);
			}
		}
		else if (j == a.size()) {
			i++;
		}
	}
	cout << l << " " << r;
} 