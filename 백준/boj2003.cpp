#include <iostream>
using namespace std;
#define io ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int n, m, ans = 0;
int ar[10001];
int main()
{
    io;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    int start = 0, end = 0, sum = ar[0];
    while (end < n)
    {
        if (sum < m)
        {
            end++;
            if (end < n)
                sum += ar[end];
        }
        else if (sum > m)
        {
            sum -= ar[start];
            start++;
        }
        else if (sum == m)
        {
            sum -= ar[start];
            start++;
            end++;
            if (end < n)
                sum += ar[end];
            ans++;
        }
    }
    cout << ans;
    return 0;
}