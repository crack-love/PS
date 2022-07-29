// https://www.acmicpc.net/problem/1786

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct p1786
{
	void getindex(string& p, vector<int>& idx)
	{
		idx.resize(p.size());

		int j = 0;
		for (int i = 1; i < p.size(); ++i)
		{
			while (j > 0 && p[i] != p[j])
			{
				j = idx[j - 1];
			}

			if (p[i] == p[j])
			{
				idx[i] = ++j;
			}
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		string t, p;
		getline(cin, t);
		getline(cin, p);

		vector<int> pi;
		getindex(p, pi);

		vector<int> answer;
		int j = 0;
		for (int i = 0; i < t.size(); ++i)
		{
			while (j > 0 && t[i] != p[j])
			{
				j = pi[j - 1];
			}

			if (t[i] == p[j])
			{
				++j;
				if (j >= p.size())
				{
					answer.push_back(i - (p.size() - 1));
					j = pi[j - 1];
				}
			}
		}

		cout << answer.size() << "\n";
		for (int x : answer)
		{
			cout << x + 1 << " ";
		}

		return 0;
	}
};