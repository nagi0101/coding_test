#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX_N (20)

static bool visited[MAX_N][MAX_N];
static int arr[MAX_N][MAX_N];
static pair<int, pair<int, int>> s;
static int n;

bool isValidIdx(int ny, int nx)
{
    return ny >= 0 && ny < n && nx >= 0 && nx < n;
}

void getFishes(vector<pair<int, pair<int, int>>>& fishes)
{
    fill(&visited[0][0], &visited[n][n], false);
    
    queue<pair<int, int>> q;
    visited[s.second.first][s.second.second] = true;
    q.push(s.second);

    int dist = 1;
    while(!q.empty())
    {
        int size = q.size();
        for(size_t c = 0; c < size; ++c)
        {
            auto p = q.front(); q.pop();
            for(size_t i = 0; i < 4; ++i)
            {
                int dy[] = { -1, 0, 1, 0 };
                int dx[] = { 0, -1, 0, 1 };
                int ny = p.first + dy[i];
                int nx = p.second + dx[i];
                if(visited[ny][nx] || !isValidIdx(ny, nx) || arr[ny][nx] > s.first) continue;

                visited[ny][nx] = true;
                q.push({ ny, nx });
                if(arr[ny][nx] < s.first && arr[ny][nx] != 0) {
                    fishes.push_back({ dist, { ny, nx } });
                }
            }
        }
        ++dist;
    }
}

int main(void)
{
    cin >> n;

    for(size_t i = 0; i < n; ++i) {
    for(size_t j = 0; j < n; ++j)
    {
        int input;
        cin >> input;
        if (input == 9) { s = { 2, { i, j } }; }
        else if(input != 0) { arr[i][j] = input; }
    }}
    

    int ans = 0;
    int eat = 0;
    while(true)
    {
        vector<pair<int, pair<int, int>>> ff;
        getFishes(ff);
        if(ff.size() == 0) { break; }
        
        auto cmp = [](pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b) {
            if(a.first > b.first) { return true; }
            else if(a.first == b.first)
            {
                if (a.second.first > b.second.first) { return true; }
                else if (
                    a.second.first == b.second.first && 
                    a.second.second > b.second.second) { return true; }
            }
            return false;
        };
        priority_queue<pair<int, pair<int, int>>, std::vector<pair<int, pair<int, int>>>, decltype(cmp)> dist(cmp, ff);

        pair<int, pair<int, int>> t = dist.top();
        ans += t.first;
        arr[t.second.first][t.second.second] = 0;
        s.second = t.second;
        ++eat;
        if(eat == s.first) 
        {
            eat = 0; 
            ++s.first; 
        }
    }
    cout << ans << '\n';
    return 0;
}
