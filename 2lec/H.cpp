#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

long long delMin(vector<long long>& a) {
    long long max = -100000000000, ind = 0;
    for (size_t i = 0; i < a.size(); i++)
    {
        if (max < a[i]) {
            max = a[i];
            ind = i;
        }
    }

    a.erase(a.begin() + ind, a.begin() + ind + 1);
    return max;
}

int main()
{
    ifstream fin("input.txt");
    vector<long long> a;
    bool allminus = true;
    long long num = 0, fmi = 0, firstmax = -1000000000;
    while (fin >> num)
        a.push_back(num);
    fin.close();

    for (size_t i = 0; i < a.size(); i++)
    {
        if (a[i] >= 0) {
            allminus = false;
        }
    }

    if (allminus)
    {
        cout << delMin(a) << " " << delMin(a) << " " << delMin(a);
        return 0;
    }

    for (size_t i = 0; i < a.size(); i++)
    {
        if (a[i] > firstmax) {
            firstmax = a[i];
            fmi = i;
        }
    }

    a.erase(a.begin() + fmi, a.begin() + fmi + 1);

    long long max = a[1], min = a[0];
    long long maxi = 1, mini = 0;
    long long x = a[1], y = a[0];

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

    cout << y << " " << x << " " << firstmax;
}

