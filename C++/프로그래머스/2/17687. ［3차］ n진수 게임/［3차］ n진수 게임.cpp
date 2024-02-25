#include <string>
#include <vector>

#include <iostream>

using namespace std;

string s(int n, int i)
{
    if (n == 0) return string("0");
    string s;
    while(n != 0)
    {
        char c = n % i;
        c += c <= 9 ? '0' : 'A' - 10;
        s.push_back(c);
        n /= i;
    }
    for(size_t i = 0; i < s.size() / 2; ++i)
    {
        char c = s[i];
        s[i] = s[s.size() - i - 1];
        s[s.size() - i - 1] = c;
    }
    
    return s;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    int num = 0;
    int cm = 1;
    while(answer.size() < t)
    {
        string ds = s(num++, n);
        for(char c: ds)
        {
            if(cm == p) 
            { 
                answer.push_back(c); 
                if(answer.size() == t) { break; }
            }
            cm = cm % m + 1;
        }
    }
    
    return answer;
}