#include <string>
#include <vector>

using namespace std;

static vector<int> d;
static int t;

int dfs(vector<int>& numbers, int l)
{
    if(l == numbers.size())
    {
        int s = 0;
        for(int i: d) { s += i; }
        
        if(s == t) { return 1; }
        else { return 0; }
    }
    
    d.push_back(numbers[l]);
    int c = dfs(numbers, l + 1);
    d.pop_back();
    
    d.push_back(-numbers[l]);
    c += dfs(numbers, l + 1);
    d.pop_back();
    
    return c;
}

int solution(vector<int> numbers, int target) {
    t = target;
    
    int answer = dfs(numbers, 0);
    return answer;
}