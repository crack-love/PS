// https://www.acmicpc.net/problem/5430

#include <bits/stdc++.h>
using namespace std;

struct p5430
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		deque<int> dq;
		string p, nstr;

		int t;
		cin >> t;
		while (t--)
		{
			int n;
			cin >> p >> n;
			cin >> nstr;
			dq.clear();

			int v = 0;
			for (char c : nstr)
			{
				if (c == '[') continue;
				else if (c == ',' || c == ']')
				{
					if (v != 0)
					{
						dq.push_back(v);
						v = 0;
					}
				}
				else
				{
					v *= 10;
					v += c - '0';
				}
			}

			bool bInvDir = false;
			for (char c : p)
			{
				if (c == 'R')
				{
					bInvDir = !bInvDir;
				}
				else if (c == 'D')
				{
					if (dq.empty())
					{
						dq.clear();
						dq.push_back(-1);
						break;
					}

					if (bInvDir)
					{
						dq.pop_back();
					}
					else
					{
						dq.pop_front();
					}
				}
			}

			if (dq.size() > 0 && dq.front() == -1)
			{
				cout << "error" << "\n";
			}
			else
			{
				bool bFstPrint = true;

				cout << "[";
				while (!dq.empty())
				{
					if (bFstPrint)
					{
						bFstPrint = false;
					}
					else
					{
						cout << ",";
					}

					if (bInvDir)
					{
						cout << dq.back();
						dq.pop_back();
					}
					else
					{
						cout << dq.front();
						dq.pop_front();
					}
				}
				cout << "]" << "\n";
			}
		}

		return 0;
	}
};