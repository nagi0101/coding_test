#include <string>
#include <vector>

using namespace std;

void h(vector<vector<int>>& ans, int n, int from, int to)
{
    if(n <= 0)
    {
        return;        
    }
    h(ans, n - 1, from, 6 - (from + to));
    ans.push_back({from, to});
    h(ans, n - 1, 6 - (from + to), to);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    h(answer, n, 1, 3);
    return answer;
}