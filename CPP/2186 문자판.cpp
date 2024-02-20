// https://www.acmicpc.net/problem/2186
// gold3

#include <iostream>
#include <string>
using namespace std;

struct p2186
{
	const int dx[4] = { 0, 0, 1, -1 };
	const int dy[4] = { 1, -1, 0, 0 };

	int N, M, K;
	char g[100][101];
	string word;

	// dijk = sum d[i-x.. j-y.. k-1]
	int d[100][100][80];
	int dp(int i, int j, int k)
	{
		if (k == 0) return 1;
		if (d[i][j][k] != 0) return d[i][j][k];

		int sum = 0;
		for (int u = 1; u <= K; ++u)
		{
			for (int v = 0; v < 4; ++v)
			{
				int nx = i + dx[v] * u;
				int ny = j + dy[v] * u;
				if (nx < 0 || ny < 0 || nx >= N || ny >= M)
					continue;

				if (g[nx][ny] == word[k - 1])
				{
					sum += dp(nx, ny, k - 1);
				}
			}
		}
		return d[i][j][k] = sum;
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		
		cin >> N >> M >> K;
		for (int i = 0; i < N; ++i)
		{
			cin >> g[i];
		}
		cin >> word;

		int answer = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (g[i][j] == word.back())
				{
					answer += dp(i, j, word.size() - 1);
				}
			}
		}
		cout << answer;
		return 0;
	}
};