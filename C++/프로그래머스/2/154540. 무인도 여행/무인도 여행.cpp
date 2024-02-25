#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#include <iostream>

using namespace std;

#define MAX_N (100)

static bool v[MAX_N][MAX_N];

int bfs(vector<string>& maps, pair<int, int> p)
{
    int s = 0;
    queue<pair<int, int>> q;
    
    v[p.first][p.second] = true;
    s += maps[p.first][p.second] - '0';
    q.push(p);
    while(!q.empty())
    {
        pair<int, int> pos = q.front(); q.pop();
        
        int d[] = { -1, 1 };
        for(size_t k = 0; k < 2; ++k)
        {
            pair<int, int> npos = { 
                clamp(pos.first + d[k], 0, (int)maps.size() - 1), 
                pos.second };
            if(maps[npos.first][npos.second] != 'X' 
               && v[npos.first][npos.second] == false) 
            { 
                v[npos.first][npos.second] = true;
                s += maps[npos.first][npos.second] - '0';
                
                q.push(npos); 
            }
            
            pair<int, int> ppos = { 
                pos.first, 
                clamp(pos.second + d[k], 0, (int)maps[pos.first].size() - 1) };
            if(maps[ppos.first][ppos.second] != 'X' 
               && v[ppos.first][ppos.second] == false) 
            {
                v[ppos.first][ppos.second] = true;
                s += maps[ppos.first][ppos.second] - '0';
                q.push(ppos); 
            }
        }
    }
    return s;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    for(size_t i = 0; i < maps.size(); ++i)
    {
        for(size_t j = 0; j < maps[i].size(); ++j)
        {
            if(maps[i][j] != 'X' && v[i][j] == false)
            {
                answer.push_back(bfs(maps, { i, j }));
            }
        }
    }
    
    if(answer.size() == 0) { answer.push_back(-1); }
    else { sort(begin(answer), end(answer), [](int a, int b){ return a < b; }); }
    
    return answer;
}