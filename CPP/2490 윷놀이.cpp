// https://www.acmicpc.net/problem/2490

#include <bits/stdc++.h>
using namespace std;
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)

struct p2490
{
	int main()
	{
		char itoc[5]{ 'D','C','B','A','E' };

		for (int i = 0; i < 3; ++i)
		{
			int cnt = 0;
			for (int j = 0; j < 4; ++j)
			{
				int x;
				cin >> x;
				if (x > 0) cnt += 1;
			}
			cout << itoc[cnt] << "\n";
		}

		return 0;
	}
};