// https://www.acmicpc.net/problem/2935

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i<0||j<0||i>=r||j>= c) continue
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p2935
{
	int main()
	{
		fastio;

		string a, b, o;
		cin >> a >> o >> b;
		if (o == "+")
		{
			stack<int> s;
			int ai = a.size() - 1;
			int bi = b.size() - 1;
			while (ai >= 0 || bi >= 0)
			{
				int sum = 0;
				sum += ai >= 0 ? a[ai] - '0' : 0;
				sum += bi >= 0 ? b[bi] - '0' : 0;
				ai -= 1;
				bi -= 1;
				s.push(sum);
			}
			while (s.size() > 0)
			{
				cout << s.top();
				s.pop();
			}
		}
		else if (o == "*")
		{
			int size = a.size() + b.size() - 1;
			cout << 1;
			for (int i = 0; i < size - 1; ++i)
			{
				cout << 0;
			}
		}

		return 0;
	}
};