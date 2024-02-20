// https://www.acmicpc.net/problem/14500

#include <iostream>
#include <vector>
using namespace std;

struct p14500
{
	typedef vector<vector<int>> vec2;
	typedef vector<vec2> vec3;

	vec2 rotate(vec2 src)
	{
		vec2 dst;
		dst.resize(src[0].size());
		for (int i = 0; i < src[0].size(); ++i)
		{
			dst[i].resize(src.size());
		}

		for (int i = 0; i < src.size(); ++i)
		{
			for (int j = 0; j < src[0].size(); ++j)
			{
				dst[j][src.size() - 1 - i] = src[i][j];
			}
		}
		return dst;
	}

	void flip(vec2 src, vec2& dstr, vec2& dstc)
	{
		dstr.resize(src.size());
		dstc.resize(src.size());
		for (int i = 0; i < src.size(); ++i)
		{
			dstr[i].resize(src[0].size());
			dstc[i].resize(src[0].size());
		}

		for (int i = 0; i < src.size(); ++i)
		{
			for (int j = 0; j < src[0].size(); ++j)
			{
				int nx = src.size() - i - 1;
				int ny = src[0].size() - j - 1;
				dstr[nx][j] = src[i][j];
				dstc[i][ny] = src[i][j];
			}
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		vec3 t =
		{
			{
				{1, 1, 1, 1},
			},
			{
				{1, 1},
				{1, 1}
			},
			{
				{1, 0},
				{1, 0},
				{1, 1},
			},
			{
				{1, 0},
				{1, 1},
				{0, 1},
			},
			{
				{1, 1, 1},
				{0, 1, 0},
			},
		};

		for (int i = 0; i < 5; ++i)
		{
			vec2 src = t[i];
			for (int j = 0; j < 3; ++j)
			{
				vec2 dst = rotate(src);
				t.push_back(dst);
				src = dst;
			}
		}
		int tsize = t.size();
		for (int i = 0; i < tsize; ++i)
		{
			vec2 d0, d1;
			flip(t[i], d0, d1);
			t.push_back(d0);
			t.push_back(d1);
		}

		int map[500][500];
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin >> map[i][j];
			}
		}

		int answer = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				for (int k = 0; k < t.size(); ++k)
				{
					const vec2& ct = t[k];
					if (i + ct.size() - 1 >= n) continue;
					if (j + ct[0].size() - 1 >= m) continue;

					int sum = 0;
					for (int u = 0; u < ct.size(); ++u)
					{
						for (int v = 0; v < ct[0].size(); ++v)
						{
							if (ct[u][v] == 0) continue;
							sum += map[i + u][j + v];
						}
					}
					if (sum > answer)
						answer = sum;
				}
			}
		}

		cout << answer;
		return 0;
	}
};