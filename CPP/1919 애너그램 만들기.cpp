// https://www.acmicpc.net/problem/1919

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

using namespace std;

struct p1919
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		string a, b;
		cin >> a >> b;
		int cntA[26]{};
		int cntB[26]{};
		for (char c : a)
		{
			cntA[c - 'a'] += 1;
		}
		for (char c : b)
		{
			cntB[c - 'a'] += 1;
		}

		int asize = a.size();
		int bsize = b.size();
		int ans = 0;
		for1(i, 26)
		{
			if (cntA[i] > cntB[i])
			{
				int d = cntA[i] - cntB[i];
				asize -= d;
				ans += d;
			}
			else if (cntA[i] < cntB[i])
			{
				int d = cntB[i] - cntA[i];
				bsize -= d;
				ans += d;
			}
		}

		ans += abs(asize - bsize);
		cout << ans;

		return 0;
	}

};