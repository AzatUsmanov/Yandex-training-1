#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    ifstream fin("input.txt");
    string name, name2, command;
    long long sum;
    unordered_map<string, long long> map;
    while (fin >> command) {
        if (command == "BALANCE") {
            fin >> name;
            if (map.find(name) != map.end()) {
                cout << map[name] << endl;
            }
            else {
                cout << "ERROR" << endl;
            }
        }
        else if (command == "DEPOSIT") {
            fin >> name >> sum;
            map[name] += sum;
        }
        else if (command == "WITHDRAW") {
            fin >> name >> sum;
            map[name] -= sum;
        }
        else if (command == "TRANSFER") {
            fin >> name >> name2 >> sum;
            map[name] -= sum;
            map[name2] += sum;
        }
        else if (command == "INCOME") {
            fin >> sum;
            for (auto& account : map)
            {
                if (account.second > 0) {
                    account.second += (account.second * sum) / 100;
                }
            }
        }
    }
}