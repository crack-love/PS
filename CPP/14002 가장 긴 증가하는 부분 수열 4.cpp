// https://www.acmicpc.net/problem/14002

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p14002
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		vector<int> a;
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			int x;
			cin >> x;
			a.push_back(x);
		}

		vector<int> b;
		vector<int> mem[1001];
		vector<int> answer;

		for (int i = 0; i < a.size(); ++i)
		{
			auto it = lower_bound(b.begin(), b.end(), a[i]);
			if (it == b.end())
			{
				b.push_back(a[i]);
				mem[b.size()] = mem[b.size() - 1];
				mem[b.size()].push_back(a[i]);
				answer = mem[b.size()];
			}
			else if (a[i] < *it)
			{
				*it = a[i];
				int cnt = it - b.begin() + 1;
				mem[cnt] = mem[cnt - 1];
				mem[cnt].push_back(a[i]);
			}
		}

		cout << answer.size() << "\n";
		for (int x : answer)
		{
			cout << x << " ";
		}
		return 0;
	}
};