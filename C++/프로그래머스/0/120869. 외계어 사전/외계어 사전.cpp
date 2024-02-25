#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    int answer = 2;
    map<char, int> vc;
    for(string& c: spell)
    {
        vc[c[0]] = 0;
    }
    
    
    for(string& w: dic)
    {
        for(string& c: spell)
        {
            vc[c[0]] = 0;
        }
        for(char& c: w)
        {
            if(vc.find(c) == end(vc)) 
            {
                goto cont;
            }
            vc[c] += 1;
        }
        
        for(auto& p: vc)
        {
            if(p.second != 1)
            { 
                goto cont;
            }
        }
        answer = 1;
        break;
cont:
        ;
    }
    
    return answer;
}