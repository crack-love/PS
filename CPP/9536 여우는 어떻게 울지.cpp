// https://www.acmicpc.net/problem/9536

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p9536
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int t;
		cin >> t;
		while (cin.peek() == '\n')
			cin.get();

		while (t--)
		{
			string line;
			getline(cin, line);

			set<string> s;
			while (true)
			{
				string line1;
				getline(cin, line1);
				if (line1 == "what does the fox say?")
				{
					break;
				}

				int i = line1.find_last_of(' ');
				string w = line1.substr(i + 1);
				s.insert(w);
			}

			for (int i = 0; i < line.size(); ++i)
			{
				int j = line.find_first_of(' ', i);
				if (j == string::npos)
				{
					j = line.size();
				}

				string ss = line.substr(i, j - i);
				if (s.find(ss) == s.end())
				{
					cout << ss;
					cout << " ";
				}

				i = j;
			}

			cout << "\n";
		}

		return 0;
	}
};