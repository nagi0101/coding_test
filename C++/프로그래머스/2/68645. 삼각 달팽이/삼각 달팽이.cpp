#include <vector>

using namespace std;

static int triangle[1000][1000];

vector<int> solution(int n) {
    int to = (n + 1) * n / 2;
    int i = 0, j = 0, c = 0;
    for(int k = 1; k <= to ; ++k)
    {
        triangle[i][j] = k;
        int cc = (c + 1) % 3;
        int ni[] = { i + 1, i, i - 1 };
        int nj[] = { j, j + 1, j - 1 };
        if(ni[c] >= n || nj[c] > ni[c] || triangle[ni[c]][nj[c]] != 0
           && triangle[ni[cc]][nj[cc]] == 0) { c = cc; }
        i = ni[c]; j = nj[c];
    }
    
    vector<int> answer(to);
    auto iter = begin(answer);
    for(int i = 0; i < n; ++i)
    for(int j = 0; j <= i; ++j) 
        *iter++ = triangle[i][j];
    
    return answer;
}