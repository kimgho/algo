#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int v, e, ans = 0;
vector<pair<int, pair<int, int>>> vc;
int vertex[10001];

int find(int x)
{
    if (vertex[x] == x)
        return x;
    else
        return vertex[x] = find(vertex[x]);
}

void unionv(int x, int y)
{
    x = find(x);
    y = find(y);
    vertex[y] = x;
}

bool isCycle(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return true;
    return false;
}

int main()
{
    io;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int start, end, dist;
        cin >> start >> end >> dist;
        vc.push_back({dist, {start, end}});
    }
    sort(vc.begin(), vc.end());
    for (int i = 1; i <= v; i++)
    {
        vertex[i] = i;
    }
    for (int i = 0; i < vc.size(); i++)
    {
        if (!isCycle(vc[i].second.first, vc[i].second.second))
        {
            unionv(vc[i].second.first, vc[i].second.second);
            ans += vc[i].first;
        }
    }
    cout << ans;
    return 0;
}