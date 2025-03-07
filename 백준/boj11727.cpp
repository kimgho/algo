#include <iostream>
using namespace std;
#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int n;
int dp[1001];
int main()
{
    io;
    cin >> n;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 5;
    dp[4] = 11;
    for (int i = 5; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
    }
    cout << dp[n] << "\n";
    return 0;
}