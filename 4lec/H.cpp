#include <iostream>
#include <vector>
using namespace std;

int Conv(char c) {
	if (64 < c && c < 91) {
		return c - 39;
	}
	else if (96 < c && c < 123) {
		return c - 97;
	}
}

bool Equal(int sum1, int sum2, vector<int>& vec1, vector<int>& vec2) {
	if (sum1 != sum2) {
		return false; 
	}
	else {
		for (size_t i = 0; i < vec1.size(); i++)
		{
			if (vec1[i] != vec2[i]) {
				return false;
			}
		}
	}
	return true;
}

int main()
{
	int k, n, first, last, sum1 = 0, sum2 = 0, count = 0;
	cin >> k >> n;
	vector<char> s(k);
	vector<char> str(n);
	vector<int> a(52), temp(52);
	for (size_t i = 0; i < k; i++)
	{
		cin >> s[i];
		first = Conv(s[i]);
		sum1 += first;
		a[first]++;
	}	
	for (size_t i = 0; i < k; i++)
	{
		cin >> str[i];
		first = Conv(str[i]);
		sum2 += first;
		temp[first]++;
	}
	if (Equal(sum1, sum2, a, temp)) {
		count++;
	}
	for (size_t i = k; i < n; i++)
	{
		cin >> str[i];
		first = Conv(str[i]);
		last = Conv(str[i-k]);
		sum2 += first - last;
		temp[first]++; temp[last]--;

		if (Equal(sum1, sum2, a, temp)) {
			count++;
		}
	}
	cout << count << endl;
}