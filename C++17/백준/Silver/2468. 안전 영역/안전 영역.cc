#include <iostream>

using namespace std;

const int MAX_N = 101;
const int MAX_H = 101;

int N;
int H[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

void dfs(int u, int v, int h)
{
    visited[u][v] = true;

    int nu[] = { max(u - 1, 0), min(u + 1, N - 1) };
    int nv[] = { max(v - 1, 0), min(v + 1, N - 1) };

    for(int i = 0; i < 2; ++i)
    {
        if(H[nu[i]][v] > h && visited[nu[i]][v] == false) dfs(nu[i], v, h);
        if(H[u][nv[i]] > h && visited[u][nv[i]] == false) dfs(u, nv[i], h);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int v = 0; v < N; ++v)
    for(int u = 0; u < N; ++u)
        cin >> H[u][v];

    int maxAns = 1;
    for(int i = 0; i < MAX_H; ++i)
    {
        fill(&visited[0][0], &visited[N][N], false);
        int ans = 0;
        for(int v = 0; v < N; ++v)
        for(int u = 0; u < N; ++u)
            if(H[u][v] > i && visited[u][v] == false)
            {
                dfs(u, v, i);
                ++ans;
            }
        maxAns = max(maxAns, ans);
    }

    cout << maxAns << '\n';


    return 0;
}