#include <vector>
#include <queue>

#define MAX_N (100)

using namespace std;

static vector<int> node[MAX_N + 1];
static bool visited[MAX_N + 1];

int bfs(int n)
{
    int a = 0;
    queue<int> q;
    q.push(n);
    while(!q.empty())
    {
        int nn = q.front(); q.pop();
        visited[nn] = true;
        ++a;
        for(auto i: node[nn])
        {
            if(!visited[i]) { q.push(i); }
        }
    }
    
    return a;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = MAX_N + 1;
    
    for(int i = 0; i < wires.size(); ++i)
    {
        for(int j = 0; j <= n; ++j)
        { 
            node[j].clear();
            visited[j] = false; 
        }
        for(int j = 0; j < wires.size(); ++j)
        {
            if(j == i) continue;
            auto& v = wires[j];
            node[v[0]].push_back(v[1]);
            node[v[1]].push_back(v[0]);
        }
        
        int a = bfs(1);
        int b = -1;
        for(int j = 2; j <= n; ++j)
        {
            if(visited[j]) { continue; }
            b = bfs(j);
            break;
        }
        int diff = a > b ? a - b : b - a;
        answer = max(min(answer, diff), 0);
    }
    
    return answer;
}