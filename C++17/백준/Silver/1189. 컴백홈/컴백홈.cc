#include <iostream>
#include <queue>

using namespace std;

const int MAX = 6;

int R, C, K;
char arr[MAX][MAX];
bool visited[MAX][MAX] = { 0, };

struct point
{
    int r;
    int c;
};

int ans = 0;
void dfs(point p, int dist)
{
    if(dist > K) return;

    visited[p.r][p.c] = true;

    if(dist == K && p.r == R - 1 && p.c == C - 1) ++ans;

    point next[] = {
        point{ min(p.r + 1, R - 1), p.c },
        point{ max(p.r - 1, 0), p.c },
        point{ p.r, min(p.c + 1, C - 1) },
        point{ p.r, max(p.c - 1, 0) },
    };
    for(int i = 0; i < 4; ++i)
    {
        if(visited[next[i].r][next[i].c] == false && arr[next[i].r][next[i].c] == '.')
        {
            dfs(next[i], dist + 1);
        }
    }

    visited[p.r][p.c] = false;
}

int main()
{
    cin >> R >> C >> K;
    for(int r = R - 1; r >= 0; --r)
    {
        cin >> arr[r];
    }

    dfs(point{ 0, 0 }, 1);
    cout << ans << '\n';

    return 0;
}
