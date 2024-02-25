#include <iostream>

#define N_MAX 3 * 3 * 3 * 3 * 3 * 3 * 3

using namespace std;

int N;
int arr[N_MAX][N_MAX];
int r[3] = {0, };

void solve(const int x, const int y, const int size)
{
    bool e = true;
    int a = arr[x][y];
    for(int i = x; i < x + size; ++i)
    {
        for(int j = y; j < y + size; ++j)
        {
            if(arr[i][j] != a)
            {
                e = false;
                break;
            } 
        }
        if(e == false) break;
    }

    if(e)
    {
        if(a == -1) r[0] += 1;
        else if(a == 0) r[1] += 1;
        else r[2] += 1;
    }
    else
    {
        for(int i = x; i < x + size; i += size/3)
            for(int j = y; j < y + size; j += size/3)
                solve(i, j, size/3);
    }
}

int main()
{   
    cin >> N;
    for(size_t i = 0; i < N; ++i)
        for(size_t j = 0; j < N; ++j)
            cin >> arr[i][j];

    solve(0, 0, N);

    cout << r[0] << endl;
    cout << r[1] << endl;
    cout << r[2] << endl;

    return 0;
}