#include <iostream>
#include <string.h>

using namespace std;
#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int ar[51][51];
int t, m, n, k, x, y, ans;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(int x, int y)
{
    ar[x][y] = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= m || ny >= n)
            continue;
        if (ar[nx][ny] == 1)
            dfs(nx, ny);
    }
}
int main()
{
    io;
    cin >> t;
    while (t > 0)
    {
        cin >> n >> m >> k;
        for (int i = 0; i < k; i++)
        {
            cin >> x >> y;
            ar[x][y] = 1;
        }
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (ar[j][k] == 1)
                {
                    dfs(j, k);
                    ans++;
                }
            }
        }
        cout << ans << "\n";
        ans = 0;
        t--;
        memset(ar, 0, sizeof(ar));
    }
    return 0;
}