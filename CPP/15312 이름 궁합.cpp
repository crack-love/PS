// https://www.acmicpc.net/problem/15312

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p15312
{
	int main()
	{
		fastio;

		int c[26] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };
		string a, b;
		cin >> a >> b;

		vector<int> s;
		for (int i = 0; i < a.size(); ++i)
		{
			s.push_back(c[a[i] - 'A']);
			s.push_back(c[b[i] - 'A']);
		}

		int size = s.size();
		while (size > 2)
		{
			for (int i = 0; i < size - 1; ++i)
			{
				s[i] = s[i] + s[i + 1];
				s[i] %= 10;
			}
			size -= 1;
		}

		cout << s[0] << s[1];
		return 0;
	}
};