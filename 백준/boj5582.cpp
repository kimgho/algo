#include <iostream>
#include <algorithm>
using namespace std;
#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

string s1, s2;
int ar[4001][4001];
int ans;
int main()
{
    io;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); i++)
    {
        for (int j = 0; j < s2.length(); j++)
        {
            if (s1[i] == s2[j])
            {
                if (i == 0 || j == 0)
                    ar[i][j] = 1;
                else
                    ar[i][j] = ar[i - 1][j - 1] + 1;
                ans = max(ans, ar[i][j]);
            }
        }
    }
    cout << ans;
    return 0;
}