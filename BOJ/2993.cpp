// https://www.acmicpc.net/problem/2993

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i<0||j<0||i>=r||j>= c) continue
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p2993
{
	int main()
	{
		fastio;

		string s;
		cin >> s;

		vector<string> words;
		string word;
		for (int j = 1; j < s.size() - 1; ++j)
		{
			for (int k = j + 1; k < s.size(); ++k)
			{
				string sw = s.substr(0, j);
				reverse(all(sw));
				word.append(sw);

				sw = s.substr(j, k - j);
				reverse(all(sw));
				word.append(sw);

				sw = s.substr(k, s.size() - k);
				reverse(all(sw));
				word.append(sw);

				words.push_back(word);
				word.clear();
			}
		}

		sort(all(words));
		cout << words[0];
		return 0;
	}
};