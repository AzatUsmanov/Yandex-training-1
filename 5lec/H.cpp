#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
	long long n, k, i = 0, j = 0, max = 0, first = 0;
	cin >> n >> k;
	vector<char> a(n);
	unordered_map<char, long long> map;
	for (long long i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	while (i != a.size()) {
		//cout << i << " " << j << endl;
		if (j - i > max) {
			max = j - i;
			first = i + 1;
		}
		if (j < int(a.size()) && map[a[j]] + 1 <= k) {
			map[a[j]]++;
			j++;
		}
		else {
			map[a[i]]--;
			i++;
		}
	}
	cout << max << " " << first;
}
