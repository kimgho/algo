#include <iostream>
#include <stack>
using namespace std;
#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main()
{
    io;
    int n;
    stack<int> st;
    string cmd;

    cin >> n;
    while (n--)
    {
        cin >> cmd;

        switch (cmd[0])
        {
        case 'p':
            if (cmd[1] == 'u')
            {
                int x;
                cin >> x;
                st.push(x);
            }
            else
            {
                if (st.empty())
                    cout << "-1\n";
                else
                {
                    cout << st.top() << '\n';
                    st.pop();
                }
            }
            break;

        case 's':
            cout << st.size() << '\n';
            break;

        case 'e':
            cout << st.empty() << '\n';
            break;

        case 't':
            cout << (st.empty() ? -1 : st.top()) << '\n';
            break;
        }
    }
    return 0;
}