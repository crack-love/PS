// https://www.acmicpc.net/problem/13506

#include <bits/stdc++.h>
using namespace std;

struct p13506
{
	int main()
	{
		//ios::sync_with_stdio(0);
		//cin.tie(0);
		//cout.tie(0);

		//string s;
		//cin >> s;

		//// get sf
		//int f0[(int)1e6] = {};
		//int j = 0;
		//for (int i = 1; i < s.size(); ++i)
		//{
		//	while (j > 0 && s[i] != s[j])
		//	{
		//		j = f0[j - 1];
		//	}
		//	if (s[i] == s[j])
		//	{
		//		f0[i] = ++j;
		//	}
		//}
		//int sfsize = j;
		//int sfbeg = s.size() - sfsize;

		//// get pf
		//int f1[(int)1e6] = {};
		//j = 0;
		//for (int i = 0; i < s.size() - 1; ++i)
		//{
		//	while (j > 0 && s[i] != s[sfbeg + j])
		//	{
		//		j = f1[j - 1];
		//	}
		//	if (s[i] == s[sfbeg + j])
		//	{
		//		f1[i] = ++j;
		//		if (j >= sfsize)
		//		{
		//			break;
		//		}
		//	}
		//}
		//int pfsize = j;

		//if (pfsize == sfsize)
		//{

		//}
		//
		//int mfsize = 0;
		//for (int i = 1; i < s.size() - 1; ++i)
		//{
		//	mfsize = max(mfsize, f0[i]);
		//}
		//int tksize = min(sfsize, pfsize);
		//tksize = min(tksize, (int)s.size() - tksize);
		//mfsize -= mfsize % tksize; 

		//if (mfsize == 0)
		//{
		//	cout << "-1";
		//}
		//else
		//{
		//	for (int i = 0; i < mfsize; ++i)
		//	{
		//		cout << s[i];
		//	}
		//}

		//return 0;
	}
};