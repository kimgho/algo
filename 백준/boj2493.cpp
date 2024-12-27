#include <iostream>
#include <stack>

using namespace std;
#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int n, hegiht;
int main()
{
    io;
    cin >> n;
    stack<pair<int, int>> st; // first = 인덱스, second = 탑 높이
    for (int i = 1; i <= n; i++)
    {
        cin >> hegiht; // 탑 높이 입력받음
        if (st.empty())
        {
            st.push({i, hegiht});
            cout << "0 "; // 왼쪽 방향에 자신보다 높은 탑이 없음
        }
        else
        {
            while (!st.empty())
            {
                if (st.top().second > hegiht) // 현재 탑의 높이(st.top)이 왼쪽 탑보다 큰 경우
                {
                    cout << st.top().first << " ";
                    break;
                }
                else
                {
                    st.pop();
                }
            }
        }
        if (st.empty())
        {
            cout << "0 ";
        }
        st.push({i, hegiht});
    }
    return 0;
}