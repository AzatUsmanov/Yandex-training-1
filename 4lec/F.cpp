#include <fstream>
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    ifstream fin("input.txt");
    string name, product;
    long long price;
    map<string, map<string, long long>> map;
    while (fin >> name >> product >> price) {
        map[name][product] += price;
    }
    for (auto& item1 : map)
    {
        cout << item1.first << ":" << endl;
        for (auto& item2 : item1.second)
        {
            cout << item2.first << " " << item2.second << endl;
        }
    }
}