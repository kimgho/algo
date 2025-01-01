#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int n, m;
vector<int> v[101];
bool visited[101];

int bfs(int start)
{
    queue<int> q;
    int cnt = 0;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < v[x].size(); i++)
        {
            if (!visited[v[x][i]])
            {
                q.push(v[x][i]);
                cnt++;
                visited[v[x][i]] = true;
            }
        }
    }
    return cnt;
}

int main()
{
    io;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cout << bfs(1);
    return 0;
}