// https://www.acmicpc.net/problem/1439

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p1439
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int zs = 0;
		int os = 0;
		const int bufSize = 1024;
		char buff[bufSize];
		char last = 1;
		while (last != 0)
		{
			cin.get(buff, bufSize);

			for (int i = 0; i < bufSize - 1; ++i)
			{
				if (buff[i] == 0)
				{
					last = 0;
					break;
				}

				if (buff[i] != last)
				{
					last = buff[i];

					if (buff[i] == '0')
					{
						zs += 1;
					}
					else if (buff[i] == '1')
					{
						os += 1;
					}
				}
			}
		}

		cout << min(zs, os);

		return 0;
	}
};