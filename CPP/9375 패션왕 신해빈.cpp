// https://www.acmicpc.net/problem/9375

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p9375
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int t;
		cin >> t;
		while (t--)
		{
			int n;
			cin >> n;
			string name, type;
			unordered_map<string, int> cnt;
			int typeCnt = 0;

			for (int i = 0; i < n; ++i)
			{
				cin >> name >> type;

				auto it = cnt.find(type);
				if (it == cnt.end())
				{
					cnt.insert(it, { type, 1 });
					typeCnt += 1;
				}
				else
				{
					(*it).second += 1;
				}
			}

			int answer = 1;
			if (typeCnt == 1)
			{
				for (auto& pair : cnt)
				{
					answer = pair.second;
				}
			}
			else
			{
				for (auto& pair : cnt)
				{
					answer *= (pair.second + 1);
				}
				answer -= 1;
			}
			cout << answer << "\n";
		}

		return 0;
	}
};