#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int n, m;
map<string, bool> no_listen;
vector<string> no_listen_see;
int main()
{
    io;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        no_listen.insert({a, true});
    }
    for (int i = 0; i < m; i++)
    {
        string a;
        cin >> a;
        if (no_listen[a])
        {
            no_listen_see.push_back(a);
        }
    }
    cout << no_listen_see.size() << "\n";
    sort(no_listen_see.begin(), no_listen_see.end());
    for (auto s : no_listen_see)
    {
        cout << s << "\n";
    }
    return 0;
}
