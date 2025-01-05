#include <iostream>
#include <math.h>
#include <limits.h>

using namespace std;
#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int n;
int ar[100001];
int main()
{
    io;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }

    int left = 0, right = n - 1, sum = INT_MAX;
    int r_index = 0, l_index = 0;

    while (left < right)
    {
        int fusion = ar[left] + ar[right];
        if (abs(fusion) < abs(sum))
        {
            sum = fusion;
            r_index = ar[right];
            l_index = ar[left];
        }
        else if (fusion > 0)
        {
            --right;
        }
        else if (fusion < 0)
        {
            ++left;
        }
        else if (fusion == 0)
        {
            break;
        }
    }
    cout << l_index << " " << r_index << "\n";
    return 0;
}