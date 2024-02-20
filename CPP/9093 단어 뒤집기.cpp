// https://www.acmicpc.net/problem/9093

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p9093
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int t;
		string ts;
		getline(cin, ts);
		t = stoi(ts);

		while (t--)
		{
			string s;
			getline(cin, s);

			int beg = 0;
			for (int i = 0; i < s.size(); ++i)
			{
				if (isspace(s[i]))
				{
					for (int j = i - 1; j >= beg; --j)
					{
						cout << s[j];
					}
					beg = i + 1;
					cout << " ";
				}
			}
			for (int i = s.size() - 1; i >= beg; --i)
			{
				cout << s[i];
			}
			cout << "\n";
		}

		return 0;
	}
};