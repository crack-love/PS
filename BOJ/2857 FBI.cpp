// https://www.acmicpc.net/problem/2857

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

using namespace std;

struct p2857
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		vector<int> ans;
		for1(i, 5)
		{
			string s;
			cin >> s;

			if (s.find("FBI") != s.npos)
			{
				ans.push_back(i + 1);
			}
		}

		if (ans.size() > 0)
		{
			for1(i, ans.size())
			{
				cout << ans[i] << " ";
			}
		}
		else
		{
			cout << "HE GOT AWAY!";
		}

		return 0;
	}
};