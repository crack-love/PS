// https://www.acmicpc.net/problem/17478

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p17478
{
	string start = "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.";
	string open = "\"����Լ��� ������?\"";
	vector<string> loop =
	{
		"\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.",
		"���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.",
		"���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\""
	};
	string loopEnd = "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"";
	string close = "��� �亯�Ͽ���.";
	string indent = "____";

	void printIndent(int depth)
	{
		for (int i = 0; i < depth; ++i)
		{
			cout << indent;
		}
	}

	void print(int depth, int n)
	{
		printIndent(depth);
		cout << open << "\n";
		if (n == 0)
		{
			printIndent(depth);
			cout << loopEnd << "\n";
		}
		else
		{
			for (string& s : loop)
			{
				printIndent(depth);
				cout << s << "\n";
			}
			print(depth + 1, n - 1);
		}
		printIndent(depth);
		cout << close << "\n";
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		cin >> n;
		cout << start << "\n";
		print(0, n);

		return 0;
	}
};