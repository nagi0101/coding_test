#include <iostream>
#include <list>

using namespace std;

const int MAX_N = 5000;

int N;
int K;
list<int> l;

int main()
{
    cin.tie(0);
    cin >> N;
    cin >> K;
    for(int i = 1; i <= N; ++i)
    {
        l.push_back(i);
    }


    list<int> r;
    auto iter = l.begin();
    for(int i = 0; i < N; ++i)
    {
        for(int k = 1; k < K; ++k)
        {
            if(iter == --l.end())
            {
                iter = l.begin();
            }
            else
            {
                ++iter;
            }
        }
        r.push_back(*iter);

        if(iter == --l.end())
        {
            l.erase(iter);
            iter = l.begin();
        }
        else
        {
            iter = l.erase(iter);
        }
    }
    
    
    cout << '<';
    for(auto iter = r.begin(); iter != r.end(); ++iter)
    {
        cout << *iter;
        if(iter != --r.end())
        {
            cout << ", ";
        }
    }
    cout << '>' << '\n';

    return 0;
}