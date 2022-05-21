// https://www.acmicpc.net/problem/1212
// b3

#include <string>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);

	string oct;
	cin >> oct;

	if (oct == "0")
	{
		cout << "0";
		return 0;
	}

	string temp(3, '0');
	for (int i = 0; i < oct.size(); ++i)
	{
		int f = oct[i] - '0';
		for (int j = 0; j < 3; ++j)
		{
			temp[3 - j - 1] = f % 2 + '0';
			f /= 2;
		}

		if (i == 0)
		{
			int oneidx = temp.find('1');
			cout << temp.substr(oneidx, 3 - oneidx);
		}
		else
		{
			cout << temp;
		}
	}

	return 0;
}