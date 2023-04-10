#include <iostream>
#include <map>
using namespace std;

int main()
{
	string s1, s2;
	int n;
	map<string, string> m1;
	map<string, string> m2;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> s1 >> s2;
		m1[s1] = s2;
		m2[s2] = s1;
	}
	cin >> s1;
	if (m1.find(s1) != m1.end()) {
		cout << m1[s1];
	}
	else if (m2.find(s1) != m2.end()) {
		cout << m2[s1];
	}
}

