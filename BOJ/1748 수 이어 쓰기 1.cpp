// https://www.acmicpc.net/problem/1748

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p1748
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int  n;
		cin >> n;

		// 1~9, 10~99 ...
		int answer = 0;
		int size = 0;
		int beg = 0;
		int end = 0;
		while (end < n)
		{
			size += 1;
			beg = end + 1;

			// get end
			end = 0;
			int endlv = 1;
			for (int i = 0; i < size; ++i)
			{
				end += endlv * 9;
				endlv *= 10;
			}
			end = min(end, n);

			answer += size * (end - beg + 1);
		}

		cout << answer;
		return 0;
	}
};