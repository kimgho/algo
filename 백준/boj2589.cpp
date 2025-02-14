#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;
#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int n, m, dist = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char map[51][51];
int visited[51][51] = {
    0,
};

void bfs(int y, int x)
{
    memset(visited, 0, sizeof(visited));
    visited[y][x] = 1;
    queue<pair<int, int>> q;
    q.push({y, x});
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny >= n || ny < 0 || nx >= m)
                continue;
            if (map[ny][nx] == 'W' || visited[ny][nx])
                continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
            dist = max(dist, visited[ny][nx]);
        }
    }
    return;
}

void map_init()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }
}

void exeBfs()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 'L')
            {
                bfs(i, j);
            }
        }
    }
    cout << dist - 1 << "\n";
}

int main()
{
    io;
    map_init();
    exeBfs();
    return 0;
}