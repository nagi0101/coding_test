#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

static int g[50][50];
static int s[50][3];
static int a[50];

int solution(vector<string> friends, vector<string> gifts) {
    map<string, int> id;
    for(size_t i = 0; i < friends.size(); ++i)
    {
        id.insert({friends[i], i});
    }
    
    for(auto str:gifts)
    {
        auto space = str.find(" ");
        auto giver = str.substr(0, space);
        auto taker = str.substr(space + 1, str.size());
        
        ++g[id[giver]][id[taker]];
        ++s[id[giver]][0];
        ++s[id[taker]][1];
    }
    for(size_t i = 0; i < friends.size(); ++i)
    {
        s[i][2] = s[i][0] - s[i][1];
    }
    
    for(size_t i = 0; i < friends.size(); ++i)
    {
        for(size_t j = 0; j < friends.size(); ++j)
        {
            if(g[i][j] > g[j][i])
            {
                ++a[i];
            }
            else if (g[i][j] == g[j][i] && s[i][2] > s[j][2])
            {
                ++a[i];
            }
        }
    }
    
    int answer = *max_element(a, a + (sizeof(a) / sizeof(a[0])));
    return answer;
}