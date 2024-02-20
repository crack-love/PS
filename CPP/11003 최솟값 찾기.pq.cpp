// https://www.acmicpc.net/problem/11003

#include <bits/stdc++.h>
using namespace std;

struct p11003_pq
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		int n, l;
		cin >> n >> l;
		typedef pair<int, int> pii;
		priority_queue<pii, vector<pii>, greater<pii>> pq;

		for (int i = 0; i < n; ++i)
		{
			int x;
			cin >> x;
			
			while (!pq.empty() && pq.top().second < i - l + 1)
			{
				pq.pop();
			}
			pq.push({x, i});
			cout << pq.top().first << " ";
		}

		return 0;
	}
};