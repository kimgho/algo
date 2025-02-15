#include <iostream>
#include <stack>
#include <vector>

using namespace std;
#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int n;
string cmd;
stack<int> st;
int main()
{
    io;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> cmd;
        if (cmd == "push")
        {
            int a;
            cin >> a;
            st.push(a);
        }
        if (cmd == "pop")
        {
            if (!st.empty())
            {
                cout << st.top() << "\n";
                st.pop();
            }
            else
            {
                cout << -1 << "\n";
            }
        }
        if (cmd == "size")
        {
            cout << st.size() << "\n";
        }
        if (cmd == "empty")
        {
            if (st.empty())
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        if (cmd == "top")
        {
            if (st.empty())
                cout << -1 << "\n";
            else
                cout << st.top() << "\n";
        }
    }
    return 0;
}