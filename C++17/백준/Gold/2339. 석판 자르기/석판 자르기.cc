#include <iostream>

using namespace std;

int N;
int arr[20][20][2];

int solve(const int s[], const int e[], const bool b)
{
    int uc = 0;
    int cc = 0;
    for(int i = s[0]; i <= e[0]; ++i)
    {
        for(int j = s[1]; j <= e[1]; ++j)
        {
            if (arr[i][j][0] == 1) ++uc;
            else if(arr[i][j][0] == 2) ++cc;
        }
    }
    if(cc == 0) return 0;
    else if(cc == 1)
    {
        if(uc == 0) return 1;
        else return 0;
    } 
    if(uc == 0) return 0;

    int r = 0;
    for(int i = s[!b] + 1; i < e[!b]; ++i)
    {
        bool cf = false;
        for(int j = s[b]; j <= e[b]; ++j)
        {
            if(arr[i][j][!b] == 1)
            {
                cf = true;
            } 
            else if(arr[i][j][!b] == 2)
            {
                cf = false;
                break;
            }
        }
        if(cf == false) continue;


        int te[2][2] = {{e[0], i - 1}, {i - 1, e[1]}};
        int ts[2][2] = {{s[0], i + 1}, {i + 1, s[1]}};
        int first = solve(s, te[b], !b);
        int second = solve(ts[b], e, !b);
        r += first * second;
    }
    return r;
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
        {
            cin >> arr[i][j][0];
            arr[j][i][1] = arr[i][j][0];
        }

    int s[2] = {0, 0};
    int e[2] = {N-1, N-1};
    int r = solve(s, e, true) + solve(s, e, false);


    if(r > 0)
    {
        cout << r << '\n';
    }
    else
    {
        cout << -1 << '\n';
    }

    return 0;

}