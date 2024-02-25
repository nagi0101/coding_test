#include <iostream>

using namespace std;

int check(int A[][64], int x, int y, int n)
{
    int r = A[y][x];

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(r != A[y+i][x+j])
                return -1;

    return r;
}

void s(int A[][64], int x, int y, int N)
{
    int ch = check(A, x, y, N);
    if(ch != -1){
        cout << ch;
        return;
    }
    
    cout << '(';
    
    int c = N/2;
    int X[2]={x, x+c};
    int Y[2]={y, y+c};
    for(int i=0; i < 2; i++)
        for(int j=0; j<2; j++)
            s(A, X[j], Y[i], c);

    cout << ')';
}

int main()
{
    int A[64][64];
    int N;

    cin >> N;
    cin.get();

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N+1; j++)
        {
            int t;
            t = cin.get();
            if(t=='0')
            {
                A[i][j]=0;
            }
            else if(t=='1')
            {
                A[i][j]=1;
            }
        }
    }

    s(A, 0, 0, N);
    cout << endl;
    
    return 0;
}