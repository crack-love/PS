// https://www.acmicpc.net/problem/5622
// bronze2

#include <iostream>
using namespace std;

struct p5622
{
	int main()
	{
		int aton[26];
		int num = 2;
		int i = 0;
		while (i < 26)
		{
			aton[i] = num;
			aton[i + 1] = num;
			aton[i + 2] = num;
			if (i == 'P' - 'A' || i == 'W' - 'A')
			{
				aton[i + 3] = num;
				++i;
			}
			i += 3;
			++num;
		}

		int answer = 0;
		char str[16] = {};
		cin >> str;
		for (char c : str)
		{
			if (c == 0) break;
			if (c >= 'a') c = c - 'a' + 'A';
			answer += aton[c - 'A'] + 1;
		}

		cout << answer;
		return 0;
	}
};