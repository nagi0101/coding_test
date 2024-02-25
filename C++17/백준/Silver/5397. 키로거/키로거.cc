#include <iostream>
#include <list>

using namespace std;

const int MAX_L = 1000001;

int main()
{
    int I;
    cin >> I;

    for(int i = 0; i < I; ++i)
    {
        list<char> l;
        auto cur = l.begin();
        char s[MAX_L];
        cin >> s;

        for(int k = 0; s[k] != '\0'; ++k)
        {
            char c = s[k];
            if(c == '<')
            {
                if(cur != l.begin())
                {
                    --cur;
                }
            }
            else if (c == '>') 
            {
                if(cur != l.end())
                {
                    ++cur;
                }
            }
            else if (c == '-')
            {
                if(cur != l.begin())
                {
                    cur = l.erase(--cur);
                }
            }
            else
            {
                l.insert(cur, c);
            }
        }

        for(auto c : l)
        {
            cout << c;
        }
        cout << '\n';
        l.clear();
    }


    return 0;
}