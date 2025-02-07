#include <iostream>
#include <set>

using namespace std;
#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int n;

int main()
{
	io;
	cin >> n;
	while (n--)
	{
		int k;
		cin >> k;
		multiset<int> ms;
		for (int i = 0; i < k; i++)
		{
			char c;
			int x;
			cin >> c >> x;
			if (c == 'I')
			{
				ms.insert(x);
			}
			else if (c == 'D' && !ms.empty())
			{
				if (x == 1)
				{
					auto it = ms.end();
					--it;
					ms.erase(it);
				}
				else if (x == -1)
				{
					ms.erase(ms.begin());
				}
			}
		}
		if (ms.empty())
		{
			cout << "EMPTY" << "\n";
		}
		else
		{
			auto it = ms.end();
			--it;
			cout << *it << " " << *ms.begin() << "\n";
		}
	}
	return 0;
}