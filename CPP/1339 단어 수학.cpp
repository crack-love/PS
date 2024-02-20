// https://www.acmicpc.net/problem/1339

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p1339
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		vector<char> alp;
		int cnt[10][26]{};
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			string s;
			cin >> s;
			for (int j = 0; j < s.size(); ++j)
			{
				char a = s[s.size() - j - 1];
				cnt[j][a - 'A'] += 1;

				if (find(alp.begin(), alp.end(), a) == alp.end())
				{
					alp.push_back(a);
				}
			}
		}

		long long answer = 0;
		sort(alp.begin(), alp.end());
		do
		{
			long long sum = 0;
			int num = 9;
			for (char c : alp)
			{
				int cAsInt = c - 'A';

				int lvl = 1;
				for (int i = 0; i < 10; ++i)
				{
					sum += (long long)cnt[i][cAsInt] * num * lvl;
					lvl *= 10;
				}
				num -= 1;
			}

			if (sum > answer) answer = sum;
		} while (next_permutation(alp.begin(), alp.end()));

		cout << answer;
		return 0;
	}
};