#include <fstream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    string s;
    vector<int> ans;
    unordered_map<string, int> map;

    while (fin >> s) {
        if (map.find(s) == map.end()) {
            map[s] = 0;
        }
        ans.push_back(map[s]++);
    }
    fin.close();

    for (size_t i = 0; i < ans.size(); i++)
    {
        fout << ans[i] << " ";
    }
}