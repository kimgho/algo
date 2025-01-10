#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int n, answer = 1;
vector<int> ar;
vector<int> lis;
int main()
{
    io;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        ar.push_back(a);
    }
    lis.push_back(ar[0]);
    for (int i = 1; i < n; i++)
    {
        if (lis.back() < ar[i])
        {
            lis.push_back(ar[i]);
        }
        else
        {
            int loc = lower_bound(lis.begin(), lis.end(), ar[i]) - lis.begin();
            lis[loc] = ar[i];
        }
    }
    cout << lis.size() << "\n";
    return 0;
}