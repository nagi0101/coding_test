#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <cstring>

#define MAX_N (20'000)

#include <iostream>

using namespace std;

static int visited[MAX_N + 1];
static vector<vector<int>> node(MAX_N + 1);

int solution(int n, vector<vector<int>> edge) {
    memset(visited, -1, sizeof(visited));
    for(auto& i: edge)
    {
        node[i[0]].push_back(i[1]);
        node[i[1]].push_back(i[0]);
    }
    
    deque<int> dq;
    dq.push_back(1);
    visited[1] = 0;
    while(!dq.empty())
    {
        int n = dq.front();
        dq.pop_front();
        for(auto& nn: node[n])
        {
            if(visited[nn] == -1)
            {
                visited[nn] = visited[n] + 1;
                dq.push_back(nn);
            }
        }
    }
    
    int m = *max_element(begin(visited), end(visited));
    int answer = count_if(begin(visited), end(visited), [&m](auto a){ return a == m; });
    return answer;
}