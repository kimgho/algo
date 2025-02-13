#include <iostream>
#include <vector>

using namespace std;
#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int a, b, c, inTime, outTime, sum;
vector<int> cnt(101);
int main()
{
    io;
    cin >> a >> b >> c;
    for (int i = 0; i < 3; i++)
    {
        cin >> inTime >> outTime;
        for (int j = inTime; j < outTime; j++)
        {
            cnt[j]++;
        }
    }
    for (int j = 1; j < 100; j++)
    {
        if (cnt[j])
        {
            if (cnt[j] == 1)
                sum += a;
            else if (cnt[j] == 2)
                sum += b * 2;
            else if (cnt[j] == 3)
                sum += c * 3;
        }
    }
    cout << sum << "\n";
    return 0;
}