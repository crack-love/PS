// https://www.acmicpc.net/problem/4435

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i<0||j<0||i>=r||j>= c) continue
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p4435
{
	int main()
	{
		fastio;

		int t;
		cin >> t;
		for (int ti = 0; ti < t; ++ti)
		{
			const vector<int> sc1 = { 1,2,3,3,4,10 };
			const vector<int> sc2 = { 1,2,2,2,3,5,10 };
			int s1 = 0;
			int s2 = 0;
			for1(i, sc1.size())
			{
				int x;
				cin >> x;
				s1 += sc1[i] * x;
			}
			for1(i, sc2.size())
			{
				int x;
				cin >> x;
				s2 += sc2[i] * x;
			}
			cout << "Battle " << ti + 1 << ": ";
			if (s1 > s2)
			{
				cout << "Good triumphs over Evil";
			}
			else if (s2 > s1)
			{
				cout << "Evil eradicates all trace of Good";
			}
			else
			{
				cout << "No victor on this battle field";
			}
			cout << "\n";
		}

		return 0;
	}
};