#include <fstream>
#include <iostream>
#include <vector>
using namespace std;


int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    vector<long long> a;
    long long num = 0;

    while (fin >> num)
        a.push_back(num);
    fin.close();

    long long x = a[1], y = a[0];
    long long max = a[1], min = a[0];
    long long maxi = 1, mini = 0;

    for (size_t i = 0; i < a.size(); i++)
    {
        if (a[i] > max) {
            max = a[i];
            maxi = i;
        }
        if (min > a[i]) {
            min = a[i];
            mini = i;
        }
    }

    for (size_t i = 0; i < a.size(); i++)
    {
        if (i != maxi && a[i] * max >= x * y) {
            x = max;
            y = a[i];
        }
        if (i != mini && a[i] * min >= x * y) {
            x = a[i];
            y = min;
        }
    }

    fout << y << " " << x;
}

