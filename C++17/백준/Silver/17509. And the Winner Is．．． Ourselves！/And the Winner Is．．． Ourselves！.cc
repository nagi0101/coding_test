#include <iostream>
#include <algorithm>

using namespace std;

typedef struct
{
    int d;
    int v;
} PROBLEM;

bool compare(const PROBLEM &p1, const PROBLEM &p2);

int main()
{
    int ans=0;
    PROBLEM problems[11];

    for(int i=0; i<11; i++)
    {
        cin >> problems[i].d;
        cin >> problems[i].v;
    }

    sort(problems, problems+11, compare);

    int totalTime=0;
    for(int i=0; i<11; i++)
    {
        totalTime+=problems[i].d;
        ans+=totalTime+problems[i].v*20;
    }
    
    cout << ans << endl;
    return 0;
}

bool compare(const PROBLEM &p1, const PROBLEM &p2)
{
    return p1.d < p2.d;
}