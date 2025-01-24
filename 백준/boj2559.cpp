#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int n, k, ans = INT_MIN;
int ar[100001];
int main()
{
    io;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        ar[i] = ar[i - 1] + a;
    }
    for (int i = k; i <= n; i++)
    {
        ans = max(ans, ar[i] - ar[i - k]);
    }
    cout << ans;
    return 0;
}
