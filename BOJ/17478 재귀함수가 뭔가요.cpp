// https://www.acmicpc.net/problem/17478

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p17478
{
	string start = "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.";
	string open = "\"재귀함수가 뭔가요?\"";
	vector<string> loop =
	{
		"\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.",
		"마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.",
		"그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\""
	};
	string loopEnd = "\"재귀함수는 자기 자신을 호출하는 함수라네\"";
	string close = "라고 답변하였지.";
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