#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int n;
int answer = 1;

bool compare(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main()
{
    io;
    cin >> n;
    vector<pair<int, int>> vc;
    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        vc.push_back({end, start});
    }
    sort(vc.begin(), vc.end(), compare);

    int firstRoom = vc[0].first;

    for (int i = 1; i < n; i++)
    {
        if (vc[i].second >= firstRoom)
        {
            answer++;
            firstRoom = vc[i].first;
        }
    }
    cout << answer;
    return 0;
}