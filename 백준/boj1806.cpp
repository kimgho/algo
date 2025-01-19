#include <iostream>
#include <math.h>
#include <limits.h>
using namespace std;
#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int n, s;
int ar[100001];
int main()
{
    io;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    int start = 0, end = 0, sum = ar[0];
    int ans = INT_MAX;
    while (start <= end && end <= n)
    {
        if (sum >= s)
        {
            ans = min(ans, end - start + 1);
        }
        if (sum < s)
        {
            end++;
            sum += ar[end];
        }
        else
        {
            sum -= ar[start];
            start++;
        }
    }
    if (ans == INT_MAX)
        cout << 0 << "\n";
    else
        cout << ans << "\n";
    return 0;
}