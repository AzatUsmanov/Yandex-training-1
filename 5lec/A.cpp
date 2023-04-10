#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector <long long> a, b;
	int n;
	cin >> n;
	a.resize(n);
	for (size_t i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cin >> n
    ;
	b.resize(n);
	for (size_t i = 0; i < n; i++)
	{
		cin >> b[i];
	}

	long long i = 0, j = 0, min = 100000000, x, y;

	while (i != a.size() && j != b.size())
	{
		if (abs(a[i] - b[j]) < min) {
			min = abs(a[i] - b[j]);
			x = a[i]; y = b[j];
		}
		if (a[i] <= b[j] && i < a.size()) {
			i++;
		}
		else if (a[i] >= b[j] && j < b.size()) {
			j++;
		}
	}

	cout << x << " " << y;
}