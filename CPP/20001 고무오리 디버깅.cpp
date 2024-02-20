// https://www.acmicpc.net/problem/20001

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i<0||j<0||i>=r||j>= c) continue
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p20001
{
	int main()
	{
		fastio;

		string s;
		getline(cin, s);

		int pcnt = 0;
		while (true)
		{
			getline(cin, s);
			if (s == "문제")
			{
				pcnt += 1;
			}
			else if (s == "고무오리")
			{
				if (pcnt == 0)
				{
					pcnt += 2;
				}
				else
				{
					pcnt -= 1;
				}
			}
			else if (s == "고무오리 디버깅 끝")
			{
				break;
			}
		}

		if (pcnt <= 0)
		{
			cout << "고무오리야 사랑해";
		}
		else
		{
			cout << "힝구";
		}

		return 0;
	}
};