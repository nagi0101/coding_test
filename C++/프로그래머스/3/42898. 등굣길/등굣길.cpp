#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

#define MAX_M (100)

static bool is_puddle[MAX_M + 1][MAX_M + 1];
static int dp[MAX_M + 1][MAX_M + 1];

int s(int m, int n)
{
    if (dp[m][n] != 0) return dp[m][n];
    
    int c = 0;
    if(n - 1 > 0 && !is_puddle[m][n - 1]) { c += s(m, n - 1) % 1'000'000'007; }
    if(m - 1 > 0 && !is_puddle[m - 1][n]) { c += s(m - 1, n) % 1'000'000'007; }
    dp[m][n] = c % 1'000'000'007;
    return dp[m][n];
}

int solution(int m, int n, vector<vector<int>> puddles) {
    for(auto& v: puddles) { is_puddle[v[0]][v[1]] = true; }
    dp[1][1] = 1;
    int answer = s(m, n);
    
    return answer;
}