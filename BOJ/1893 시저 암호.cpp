// https://www.acmicpc.net/problem/1893

#include <bits/stdc++.h>
using namespace std;

struct p1893
{
	bool kmp(string& tex, vector<int> fail, string& decoded)
	{
		int matchCnt = 0;
		int j = 0;
		for (int i = 0; i < decoded.size(); ++i)
		{
			while (j > 0 && tex[j] != decoded[i])
			{
				j = fail[j - 1];
			}

			if (tex[j] == decoded[i])
			{
				++j;
				if (j == tex.size())
				{
					j = fail[j - 2];
					matchCnt += 1;
					if (matchCnt >= 2)
					{
						break;
					}
				}
			}
		}
		return matchCnt == 1;
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		int t;
		cin >> t;
		while (t--)
		{
			// order [3 62]
			// text [1 50000]
			// encoded [3 500000]
			string order, text, encoded;
			cin >> order >> text >> encoded;

			char next['z' + 1];
			for (int i = 0; i < order.size(); ++i)
			{
				next[order[i]] = order[(i + order.size() - 1) % order.size()];
			}

			// get fail of text
			vector<int> fail(text.size(), 0);
			int j = 0;
			for (int i = 1; i < text.size(); ++i)
			{
				while (j > 0 && text[i] != text[j])
				{
					j = fail[j - 1];
				}
				if (text[i] == text[j])
				{
					fail[i] = ++j;
				}
			}

			// get shift from encoded, compare
			vector<int> ans;
			for (int i = 0; i < order.size(); ++i)
			{
				if (i != 0)
				{
					for (int j = 0; j < encoded.size(); ++j)
					{
						encoded[j] = next[encoded[j]];
					}
				}

				if (kmp(text, fail, encoded))
				{
					ans.push_back(i);
				}
			}

			if (ans.size() == 0)
			{
				cout << "no solution\n";
			}
			else if (ans.size() == 1)
			{
				cout << "unique: " << ans[0] << "\n";
			}
			else
			{
				cout << "ambiguous: ";
				for (int i = 0; i < ans.size(); ++i)
				{
					cout << ans[i] << " ";
				}
				cout << "\n";
			}
		}

		return 0;
	}
};