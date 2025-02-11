#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

vector<int> vc;
int main()
{
	io;

	for (int i = 0; i < 9; i++)
	{
		int a;
		cin >> a;
		vc.push_back(a);
	}
	sort(vc.begin(), vc.end());
	do
	{
		int sumOfHeight = 0;
		for (int i = 0; i < 7; i++)
		{
			sumOfHeight += vc[i];
		}
		if (sumOfHeight == 100)
			break;
	} while (next_permutation(vc.begin(), vc.end()));
	for (int i = 0; i < 7; i++)
	{
		cout << vc[i] << "\n";
	}
	return 0;
}
