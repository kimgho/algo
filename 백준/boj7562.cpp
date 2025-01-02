#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;
#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 300

int t, m;
int startX, startY, goalX, goalY;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

void bfs(int startX, int startY)
{
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == goalX && y == goalY)
        {
            cout << map[goalX][goalY] << '\n';
            while (!q.empty())
                q.pop();
            break;
        }

        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if ((0 <= nx && 0 <= ny && nx < m && ny < m) && !visited[nx][ny])
            {
                visited[nx][ny] = true;
                map[nx][ny] = map[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    memset(visited, false, sizeof(visited));
}

int main()
{
    io;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> m;
        cin >> startX >> startY;
        cin >> goalX >> goalY;
        bfs(startX, startY);
        memset(map, 0, sizeof(map));
    }
    return 0;
}