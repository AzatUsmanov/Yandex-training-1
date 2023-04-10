#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    long long n, a, b, sum = 0;
    unordered_map<long long, long long> map;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        cin >> a >> b;
        if (map.find(a) != map.end()) {
            if (b > map[a]) {
                sum -= map[a];
                map[a] = b;
                sum += b;
            }
        }
        else {
            map[a] = b;
            sum += b;
        }
    }
    cout << sum << endl;
}