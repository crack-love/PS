// https://www.acmicpc.net/problem/20499

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

using namespace std;

struct p20499
{
	int parse(const string& str, int beg, int& dst)
	{
		int i = beg;
		for (i; i < str.size(); ++i)
		{
			if (str[i] == '/')
			{
				i += 1;
				break;
			}
			else
			{
				dst *= 10;
				dst += str[i] - '0';
			}
		}
		return i;
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		string kda;
		cin >> kda;
		int k = 0, d = 0, a = 0;
		int i = 0;
		i = parse(kda, i, k);
		i = parse(kda, i, d);
		i = parse(kda, i, a);

		if (d == 0 || (k + a < d))
		{
			cout << "hasu";
		}
		else
		{
			cout << "gosu";
		}

		return 0;
	}
};