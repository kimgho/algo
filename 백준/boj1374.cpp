#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int n;

bool compare(pair<int, int> &a, pair<int, int> &b)
{
    return a.first < b.first;
}

int main()
{
    io;
    cin >> n;
    int cnt = 1;
    vector<pair<int, int>> vc;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        int idx, start, end;
        cin >> idx >> start >> end;
        vc.push_back({start, end});
    }
    sort(vc.begin(), vc.end(), compare);
    for (int i = 0; i < vc.size(); i++)
    {
        if (pq.empty())
        {
            pq.push(vc[i].second);
        }
        else
        {
            if (pq.top() > vc[i].first)
            {
                cnt++;
            }
            else
            {
                pq.pop();
            }
            pq.push(vc[i].second);
        }
    }
    cout << cnt;
    return 0;
}