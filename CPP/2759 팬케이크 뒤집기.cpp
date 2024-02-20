// https://www.acmicpc.net/problem/2759

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define x first
#define y second
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p2759
{
	int main()
	{
		fastio;

		int t;
		cin >> t;
		while (t--)
		{
			int n;
			cin >> n;
			vector<int> a;
			for1(i, n)
			{
				int x;
				cin >> x;
				a.push_back(x);
			}

			vector<int> ans;
			for (int i = n; i >= 1; --i)
			{
				auto it = find(all(a), i);
				if (it == a.begin() + i - 1)
				{
					continue;
				}

				if (it != a.begin())
				{
					reverse(a.begin(), it + 1);
					ans.push_back(it - a.begin() + 1);
				}

				reverse(a.begin(), a.begin() + i);
				ans.push_back(i);
			}

			cout << ans.size() << " ";
			for (int x : ans)
			{
				cout << x << " ";
			}
			cout << "\n";
		}

		return 0;
	}
};