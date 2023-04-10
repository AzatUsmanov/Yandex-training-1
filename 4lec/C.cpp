#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <iostream>
using namespace std;

int main()
{
    ifstream fin("input.txt");
    string s, smax;
    int max = -1, i = 0;
    unordered_map<string, int> map;

    while (fin >> s) {
        i++;
        if (map.find(s) == map.end()) {
            map[s] = 0;
        }
        map[s]++;
        if (map[s] > max) {
            max = map[s];
            smax = s;
        }
        else if (map[s] == max) {
            if (strcmp(s.c_str(), smax.c_str()) < 0) {
                smax = s;
            }
        }
    }
    fin.close();
    cout << smax;
}