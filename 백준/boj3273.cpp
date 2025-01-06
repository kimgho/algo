#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int n, x, cnt = 0;
vector<int> vc;
int main()
{
    io;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        vc.push_back(a);
    }
    cin >> x;

    sort(vc.begin(), vc.end());

    int left = 0, right = n - 1;

    while (left < right)
    {
        int sum = vc[left] + vc[right];
        if (sum > x)
        {
            right--;
        }
        else if (sum < x)
        {
            left++;
        }
        else
        {
            left++;
            right--;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}