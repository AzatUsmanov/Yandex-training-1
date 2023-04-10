#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

string Tolower(string str) {
	string s = str;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (64 < str[i] && str[i] < 91) {
			s[i] = str[i] + 32;
		}
	}
	return s;
}

bool CheckCorrect(string str) {
	int count = 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (64 < str[i] && str[i] < 91) {
			count++;
		}
	}
	return count == 1;
}

bool Check(unordered_map<string, unordered_set<string>>& map, string s) {
	string low = Tolower(s);
	if (map.find(low) != map.end()) {
		return map[low].find(s) != map[low].end();;
	}
	else {
		return CheckCorrect(s);
	}
}

int main()
{
    ifstream fin("input.txt");
	int n, count = 0;
	string str;
	unordered_map<string, unordered_set<string>> map;
	fin >> n;
	for (size_t i = 0; i < n; i++)
	{
		fin >> str;
		map[Tolower(str)].insert(str);
	}

    while (fin >> str) {
		if (!Check(map, str)) {
			count++;
		}
    }

	cout << count;
}