// https://www.acmicpc.net/problem/2659

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p2659
{
	int main()
	{
		fastio;

		int v = 0;
		for (int i = 0; i < 4; ++i)
		{
			int x;
			cin >> x;
			v += (int)pow(10, 3 - i) * x;
		}

		auto getClockNum = [](int v) -> int
		{
			static set<int> s;
			s.clear();
			for (int i = 0; i < 4; ++i)
			{
				v *= 10;
				v += v / 10000;
				v %= 10000;
				s.insert(v);
			}
			return *s.begin();
		};

		int t = getClockNum(v);

		map<int, int> m;
		int c = 1;
		for (int i = 1111; i <= 9999; ++i)
		{
			int i2 = i;
			for (int j = 0; j < 4; ++j)
			{
				if (i2 % 10 == 0)
				{
					i2 = -1;
					break;
				}
				i2 /= 10;
			}
			if (i2 == -1)
				continue;

			int cn = getClockNum(i);
			auto it = m.find(cn);
			if (it == m.end())
				m.insert({ cn, c++ });
		}

		cout << m[t];
		return 0;
	}
};