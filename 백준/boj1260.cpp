#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 1001
int n, m, v;
int map[MAX][MAX];
bool visited[MAX];

void dfs(int v)
{
    visited[v] = true;
    cout << v << ' ';
    for (int i = 1; i <= n; i++)
    {
        if (map[v][i] && !visited[i])
            dfs(i);
    }
}

void bfs(int v)
{
    queue<int> q;
    q.push(v);
    visited[v] = true;
    while (!q.empty())
    {
        v = q.front();
        q.pop();
        cout << v << ' ';
        for (int i = 1; i <= n; i++)
        {
            if (map[v][i] && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main()
{
    io;
    cin >> n >> m >> v;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        map[a][b] = map[b][a] = 1;
    }
    dfs(v);
    memset(visited, false, sizeof(visited));
    cout << '\n';
    bfs(v);
    return 0;
}