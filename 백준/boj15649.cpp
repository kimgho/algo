#include <iostream>
using namespace std;
#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int n, m;
int arr[8];
bool visited[8];
void backtracking(int start)
{
    if (start == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                arr[start] = i;
                backtracking(start + 1);
                visited[i] = false;
            }
        }
    }
}
int main()
{
    io;
    cin >> n >> m;
    backtracking(0);
}