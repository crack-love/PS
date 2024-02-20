// https://www.acmicpc.net/problem/1021

#include <cassert>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int p1021()
{    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // get input
    int n, m;
    cin >> n >> m;
    vector<int> input;
    while (m--)
    {
        int x;
        cin >> x;
        input.push_back(x);
    }

    // init queue
    deque<int> q;
    for (int i = 0; i < n; ++i)
    {
        q.push_back(i + 1);
    }

    auto getLeftDistance = [&q](const int x) -> int
    {
        int cnt = 1;
        for (auto it = q.crbegin(); it != q.crend(); ++it)
        {
            if (*it == x)
            {
                return cnt;
            }
            else
            {
                ++cnt;
            }
        }

        return -1;
    };

    auto getRightDistance = [&q](const int x) -> int
    {
        int cnt = 0;
        for (auto it = q.cbegin(); it != q.cend(); ++it)
        {
            if (*it == x)
            {
                return cnt;
            }
            else
            {
                ++cnt;
            }
        }

        return -1;
    };

    int answer = 0;
    for (const int x : input)
    {
        // pop front
        if (q.front() == x)
        {
            q.pop_front();
        }
        else
        {
            // find minimum distance (l/r)
            int lcnt = getLeftDistance(x);
            int rcnt = getRightDistance(x);
            assert(lcnt != -1);
            assert(rcnt != -1);

            if (lcnt < rcnt)
            {
                answer += lcnt;
                while (lcnt--)
                {
                    q.push_front(q.back());
                    q.pop_back();
                }
            }
            else
            {
                answer += rcnt;
                while (rcnt--)
                {
                    q.push_back(q.front());
                    q.pop_front();
                }
            }

            q.pop_front();
        }
    }

    cout << answer << "\n";

    return 0;
}