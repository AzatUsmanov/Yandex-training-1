#include <iostream>
#include <map>
#include <unordered_set>
#include <vector>
using namespace std;

void Add(long long x, long long& one, long long& two, map <long long, long long>& map) {
	if (map[x] == 1) {
		one++;
	}
	else {
		one++;
		two++;
	}
	//cout << x << " " << one.size() << " " << two.size() << endl;
}

void Del(long long x, long long& one, long long& two, map <long long, long long>& map) {
	if (map[x] == 1) {
		one--;
	}
	else {
		one--;
		two--;
	}
}

long long Sum(long long x, long long& one, long long& two, map <long long, long long>& map) {
	long long sum = 0;
	switch (map[x])
	{
	case 1:
		sum += 3 * one * (one - 1) + 3 * two;
		break;
	case 2:
		sum += 3 * one * (one - 1) + 3 * two + 3 * one;
		break;
	default:
		sum += 3 * one * (one - 1) + 3 * two + 3 * one + 1;
		break;
	}
	//cout << x << " " << one << " " << two << " " << sum <<  endl;
	return sum;
}

int main()
{
	long long n, k, i = 0, j = 1, sum = 0, x;
	cin >> n >> k;
	vector<pair<long long, long long>> b;
	map <long long, long long> map;
	for (size_t i = 0; i < n; i++)
	{
		cin >> x;
		map[x]++;
	}
	b = vector<pair<long long, long long>>(map.begin(), map.end());
	vector<long long> a(b.size());
	for (size_t i = 0; i < b.size(); i++)
	{
		a[i] = b[i].first;
	}
	long long one = 1, two = int(map[a[0]] > 1);
	while (i < a.size() || j < a.size()) {
		if (j < a.size() && a[i] * k >= a[j]) {
			Add(a[j], one, two, map);
			j++;
		}
		else {
			Del(a[i], one, two, map);
			sum += Sum(a[i], one, two, map);
			i += int(i < int(a.size()));
		}
		if (i == a.size()) {
			break;
		}
	}
	cout << sum;
}