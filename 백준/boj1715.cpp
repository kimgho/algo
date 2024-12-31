#include <iostream>
#include <queue>
using namespace std;
#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
int n;
priority_queue<int, vector<int>, greater<int>> pq;
int main()
{
    io;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        pq.push(a);
    }
    for (int i = 0; i < n - 1; i++)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        ans += a + b;
        pq.push(a + b);
    }
    // ans += pq.top();
    cout << ans;
    return 0;
}