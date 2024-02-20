// https://www.acmicpc.net/problem/1969

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

using namespace std;

struct p1969
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		char itochar[4] = { 'A','C','G','T' };
		char chartoi[26];
		chartoi['A' - 'A'] = 0;
		chartoi['C' - 'A'] = 1;
		chartoi['G' - 'A'] = 2;
		chartoi['T' - 'A'] = 3;

		int num[50][4]{};
		int n, m;
		cin >> n >> m;
		for1(i, n)
		{
			string s;
			cin >> s;

			for1(j, m)
			{
				int k = chartoi[s[j] - 'A'];
				num[j][k] += 1;
			}
		}

		string ansStr;
		int ansDist = 0;
		for1(i, m)
		{
			int maxv = 0;
			int maxi = 0;
			for1(j, 4)
			{
				if (num[i][j] > maxv)
				{
					maxv = num[i][j];
					maxi = j;
				}
			}
			ansStr.push_back(itochar[maxi]);
			for1(j, 4)
			{
				if (j != maxi)
				{
					ansDist += num[i][j];
				}
			}
		}

		cout << ansStr << "\n" << ansDist;

		return 0;
	}
};