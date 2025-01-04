#include <iostream>
#include <string>
#include <stack>
using namespace std;
#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 1001

int dp[MAX][MAX];
int main()
{
    io;
    string s1, s2, answer = "";
    cin >> s1 >> s2;
    stack<char> st;

    int sz_a = s1.length();
    int sz_b = s2.length();

    for (int i = 1; i <= sz_a; ++i)
    {
        dp[i][0] = 0;
    }
    for (int j = 1; j <= sz_b; ++j)
    {
        dp[0][j] = 0;
    }
    for (int i = 1; i <= sz_a; ++i)
    {
        for (int j = 1; j <= sz_b; ++j)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    while (sz_a > 0 && sz_b > 0)
    {
        if (dp[sz_a][sz_b] == dp[sz_a - 1][sz_b])
        {
            sz_a--;
        }
        else if (dp[sz_a][sz_b] == dp[sz_a][sz_b - 1])
        {
            sz_b--;
        }
        else
        {
            st.push(s1[sz_a - 1]);
            sz_a--;
            sz_b--;
        }
    }
    cout << st.size() << "\n";

    while (!st.empty())
    {
        answer += st.top();
        st.pop();
    }
    cout << answer << "\n";

    return 0;
}