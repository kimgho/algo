#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int n, m;
string a;
unordered_map<string, int> mp;
string dogam[100001];

int main()
{
    io;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string poketmon;
        cin >> poketmon;
        mp.insert({poketmon, i});
        dogam[i] = poketmon;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> a;
        if (isdigit(a[0]))
        {
            cout << dogam[stoi(a)] << "\n";
        }
        else
        {
            cout << mp.find(a)->second << "\n";
        }
    }
    return 0;
}