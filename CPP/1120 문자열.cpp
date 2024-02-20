// https://www.acmicpc.net/problem/1120

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p1120
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		string a, b;
		cin >> a >> b;

		int answer = a.size();
		for (int i = 0; i < b.size(); ++i)
		{
			if (a.size() + i <= b.size())
			{
				int cnt = 0;
				for (int j = 0; j < a.size(); ++j)
				{
					if (a[j] != b[j + i])
					{
						cnt += 1;
					}
				}
				answer = min(answer, cnt);
			}
			else
			{
				break;
			}
		}
		cout << answer;
		return 0;
	}
};