// https://www.acmicpc.net/problem/4690

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i<0||j<0||i>=r||j>= c) continue
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p4690
{
	int main()
	{
		fastio;

		for (int a = 2; a <= 100; ++a)
		{
			for (int b = 2; b < a; ++b)
			{
				for (int c = b + 1; c < a; ++c)
				{
					for (int d = c + 1; d < a; ++d)
					{
						if (a * a * a ==
							b * b * b + c * c * c + d * d * d)
						{
							cout << "Cube = " << a << ", ";
							cout << "Triple = (" << b << ",";
							cout << c << "," << d << ")\n";
						}
					}
				}
			}
		}

		return 0;
	}
};