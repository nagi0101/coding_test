#include <string>
#include <vector>

using namespace std;

int stoday(string s)
{
    int y = stoi(s.substr(0, 4));
    int m = stoi(s.substr(5, 6));
    int d = stoi(s.substr(8, 9));
    
    return d + 28 * m + 28 * 12 * y;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    int t = stoday(today);
    
    int te[26];
    for(auto str:terms)
    {
        auto termN = str[0];
        int termD = stoi(str.substr(2, str.size())) * 28;
        te[termN - 'A'] = termD;
    }
    
    vector<int> answer;
    for(size_t i = 0; i < privacies.size(); ++i)
    {
        string pdate = privacies[i].substr(0, 10);
        char termN = privacies[i][11];
        int pd = stoday(pdate);
        int ed = pd + te[termN - 'A'];
        if(ed <= t)
        {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}