// https://www.acmicpc.net/problem/1097

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int main()
{
	// t(i) == t -> k개
	// 문자열 리스트의 순열 조합
	// 이 조합이 조건을 만족하는지

	int n, k;
	cin >> n;
	vector<string> strs;
	string strTemp;
	vector<int> order;
	for (int i = 0; i < n; ++i)
	{
		cin >> strTemp;
		strs.emplace_back(strTemp);
		order.push_back(i);
	}
	cin >> k;

	// KMP
	int pi[160] = {};
	auto setPi = [&pi](const string& src) -> void
	{
		int j = 0;
		for (int i = 1; i < src.size(); ++i)
		{
			// not match, compare with prev
			while (src[i] != src[j] && j > 0)
			{
				j = pi[j - 1];
			}

			// increase pi
			if (src[i] == src[j])
			{
				pi[i] = ++j;
			}
			else
			{
				pi[i] = 0;
			}
		}
	};

	auto getMatchCnt = [&pi, k, setPi](const string& src) -> int
	{
		setPi(src);

		static string dsrc = "";
		dsrc.clear();
		dsrc.append(src);
		dsrc.append(src);
		dsrc.pop_back();

		int matchCnt = 0;
		int j = 0;
		for (int i = 0; i < dsrc.size(); ++i)
		{
			while (dsrc[i] != src[j] && j > 0) 
			{	
				j = pi[j - 1];
			}

			if (++j >= src.size())
			{
				++matchCnt;
				j = pi[j - 1];

				// finish
				if (matchCnt > k)
					return matchCnt;
			}
		}

		return matchCnt;
	};

	// for each permutation
	string str;
	int answer = 0;
	do
	{
		str.clear();

		for (int i = 0; i < n; ++i)
		{
			str.append(strs[order[i]]);
		}

		// check match k
		int cnt = getMatchCnt(str);
		if (cnt == k)
		{
			++answer;
		}
	}
	while (next_permutation(order.begin(), order.end()));

	cout << answer;
	return  0;
}