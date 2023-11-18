// https://www.acmicpc.net/problem/9324

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p9324
{
	int main()
	{
		fastio;

		int t;
		cin >> t;
		while (t--)
		{
			string m;
			cin >> m;

			bool fail = false;
			int cnt[26]{};
			for (int i = 0; i < m.size(); ++i)
			{
				cnt[m[i] - 'A'] += 1;

				if (cnt[m[i] - 'A'] == 3)
				{
					if (i == m.size() - 1 || m[i + 1] != m[i])
					{
						fail = true;
						break;
					}
					cnt[m[i] - 'A'] = -1;
				}
			}

			cout << (fail ? "FAKE" : "OK") << "\n";
		}

		return 0;
	}
};