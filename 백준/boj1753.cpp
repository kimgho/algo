#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 999999999

int v, e, start;
vector<pair<int, int>> vc[20001];
int dist[20001];

void dijk()
{
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    dist[start] = 0;
    while (!pq.empty())
    {
        int d = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        for (int i = 0; i < vc[now].size(); i++)
        {
            int n = vc[now][i].first;
            int nweight = vc[now][i].second;
            if (dist[n] > d + nweight)
            {
                dist[n] = d + nweight;
                pq.push({-dist[n], n});
            }
        }
    }
    for (int i = 1; i <= v; i++)
    {
        if (dist[i] == INF)
        {
            cout << "INF" << "\n";
        }
        else
        {
            cout << dist[i] << "\n";
        }
    }
}

int main()
{
    io;
    cin >> v >> e >> start;
    for (int i = 0; i < e; i++)
    {
        int vec, ed, wei;
        cin >> vec >> ed >> wei;
        vc[vec].push_back({ed, wei});
    }
    fill(dist, dist + 20001, INF);
    dijk();
    return 0;
}