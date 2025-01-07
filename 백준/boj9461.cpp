#include <iostream>

using namespace std;
#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

long long dp[101];
int n;

long long solution(int a)
{
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 4; i < 101; i++)
    {
        dp[i] = dp[i - 2] + dp[i - 3];
    }
    return dp[a];
}

int main()
{
    io;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        cout << solution(a) << "\n";
    }
    return 0;
}