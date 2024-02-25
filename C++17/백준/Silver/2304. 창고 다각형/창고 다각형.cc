#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

typedef pair<int, int> column;

vector<column> v;
int N;

bool comp(const column &a, const column &b)
{
    return a.first < b.first;
}

int main()
{
    cin >> N;
    column maxc;
    for(int i = 0; i < N; ++i)
    {
        column c;
        cin >> c.first;
        cin >> c.second;
        v.push_back(c);
        if(c.second > maxc.second)
        {
            maxc = c;
        }
    }
    sort(v.begin(), v.end(), comp);

    int ans = 0;
    stack<column> ls;
    ls.push(column{0, 0});
    for(auto iter = v.begin(); iter != v.end(); ++iter)
    {
        if(iter->second > ls.top().second)
        {
            ans += ls.top().second * (iter->first - ls.top().first);
            ls.push(*iter);
        }
    }
    stack<column> rs;
    rs.push(column{0, 0});
    for(auto iter = v.rbegin(); iter != v.rend(); ++iter)
    {
        if(iter->second > rs.top().second)
        {
            ans += rs.top().second * (rs.top().first - iter->first);
            rs.push(*iter);
        }
    }
    ans += ls.top().second * (rs.top().first - ls.top().first + 1);


    cout << ans << '\n';


    return 0;
}