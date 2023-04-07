// https://www.acmicpc.net/problem/5073

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

using namespace std;

struct p5073
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		while (true)
		{
			int a, b, c;
			cin >> a >> b >> c;
			if (a == 0 && b == 0 && c == 0)
				break;

			int arr[3];
			arr[0] = a;
			arr[1] = b;
			arr[2] = c;
			sort(arr, arr + 3);
			if (arr[2] >= arr[0] + arr[1])
			{
				cout << "Invalid\n";
				continue;
			}

			if (a == b || b == c || a == c)
			{
				if (a == b && b == c)
				{
					cout << "Equilateral\n";
					continue;
				}
				else
				{
					cout << "Isosceles\n";
					continue;
				}
			}
			else
			{
				cout << "Scalene\n";
				continue;
			}
		}
	}
};