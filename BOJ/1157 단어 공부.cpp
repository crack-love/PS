// https://www.acmicpc.net/problem/1157
// bronze 1

#include <iostream>
#include <string>
using namespace std;

struct p1157
{
	int main()
	{
		int cnt[26] = {};
		string str;
		cin >> str;
		for (int i = 0; i < str.size(); ++i)
		{
			int a = str[i];
			if ('A' <= a && a <= 'Z') a -= 'A';
			else a -= 'a';
			cnt[a] += 1;
		}

		char answer = '?';
		int answerCnt = 0;
		for (int i = 0; i < 26; ++i)
		{
			if (cnt[i] > answerCnt)
			{
				answer = i + 'A';
				answerCnt = cnt[i];
			}
			else if (cnt[i] == answerCnt)
			{
				answer = '?';
			}
		}

		cout << answer;
		return 0;
	}
};