#include <iostream>
#include <list>

using namespace std;

int main(void)
{
    list<int> l;

    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        l.push_back(i);
    }

    while(l.size() > 1)
    {
        for(auto iter = l.begin(); iter != l.end() && l.size() > 1; ++iter)
        {
            l.erase(iter++);
        }
    }

    cout << l.front() << '\n';
    return 0;
}
