#include <iostream>
#include <queue>

using namespace std;
#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int n, m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int map[100][100];

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (map[nx][ny] == 0)
                continue;
            if (map[nx][ny] == 1)
            {
                map[nx][ny] = map[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main()
{
    io;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }
    bfs(0, 0);
    cout << map[n - 1][m - 1];
    return 0;
}