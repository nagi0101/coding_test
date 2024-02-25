#include <string>
#include <vector>

#include <iostream>

using namespace std;

bool check(vector<bool>& v, string& s, const char* subs, size_t subsLen)
{
    if(auto f = s.find(subs); f != string::npos)
    {
        for(size_t i = f; i < f + subsLen; ++i)
        {
            if(v[i]) return false;
            v[i] = true;
        }
    }
    return true;
}

int solution(vector<string> babbling) {
    int answer = 0;
    for(string& s: babbling)
    {
        vector<bool> v(s.size(), false);
        if(!check(v, s, "aya", 3)) continue;
        if(!check(v, s, "ye", 2)) continue;
        if(!check(v, s, "woo", 3)) continue;
        if(!check(v, s, "ma", 2)) continue;
        
        bool pass = true;
        for(bool b: v)
        {
            pass = pass && b;
        }
        if(pass) { ++answer; }
        
    }
    
    return answer;
}