#include <iostream>

using namespace std;
#define io ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int n, m;
long long arr[100001];
long long ar[100001];
int main()
{
    io;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        ar[i] += ar[i - 1] + arr[i];
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << ar[b] - ar[a - 1] << "\n";
    }
    return 0;
}