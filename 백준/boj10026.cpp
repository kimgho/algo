#include <iostream>
#include <cstring>
using namespace std;
#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int n, ans = 0;
char ar[101][101];
bool visited[101][101];
int dir_x[4] = {1, -1, 0, 0};
int dir_y[4] = {0, 0, -1, 1};

void dfs(int x, int y)
{
    if (visited[x][y])
        return;
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dir_x[i];
        int ny = y + dir_y[i];
        if ((ar[nx][ny] == ar[x][y]) && !visited[nx][ny])
            dfs(nx, ny);
    }
}

void do_dfs()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                dfs(i, j);
                ans++;
            }
        }
    }
}
void changeColor()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (ar[i][j] == 'G')
                ar[i][j] = 'R';
        }
    }
}
int main()
{
    io;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> ar[i][j];
        }
    }
    do_dfs();
    cout << ans << " ";
    ans = 0;
    memset(visited, false, sizeof(visited));
    changeColor();
    do_dfs();
    cout << ans;
    return 0;
}