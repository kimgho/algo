#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int n;

int main()
{
    io;
    cin >> n;
    vector<pair<int, int>> vc;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        vc.push_back({a, b});
    }
    sort(vc.begin(), vc.end());
    pq.push(vc[0].second);
    for (int i = 1; i < n; i++)
    {
        if (vc[i].first >= pq.top())
        {
            pq.pop();
            pq.push(vc[i].second);
        }
        else
        {
            pq.push(vc[i].second);
        }
    }
    cout << pq.size() << "\n";
    return 0;
}