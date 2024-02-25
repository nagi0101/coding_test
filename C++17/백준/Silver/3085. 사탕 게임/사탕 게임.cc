#include <iostream>

using namespace std;

void swap(char *a, char *b);

int main()
{
    int size;
    char board[50][50];
    int ans = 1;

    cin >> size;

    for(int i=0; i<size; i++)
    {
        cin >> board[i];
    }

    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size-1; j++)
        {
            swap(board[i][j], board[i][j+1]);

            int max=1;
            int maxTmp=1;
            for(int k=0; k<size-1; k++)
            {
                if(board[i][k]==board[i][k+1])
                {
                    maxTmp++;
                }
                else
                {
                    max = maxTmp > max ? maxTmp : max;
                    maxTmp = 1;
                }
            }
            max = maxTmp > max ? maxTmp : max;
            maxTmp = 1;
            
            for(int k=0; k<size-1; k++)
            {
                if(board[k][j]==board[k+1][j])
                {
                    maxTmp++;
                }
                else
                {
                    max = maxTmp > max ? maxTmp : max;
                    maxTmp = 1;
                }
            }
            max = maxTmp > max ? maxTmp : max;
            maxTmp = 1;

            for(int k=0; k<size-1; k++)
            {
                if(board[k][j+1]==board[k+1][j+1])
                {
                    maxTmp++;
                }
                else
                {
                    max = maxTmp > max ? maxTmp : max;
                    maxTmp = 1;
                }
            }
            max = maxTmp > max ? maxTmp : max;
            maxTmp = 1;
            
            ans = max > ans ? max : ans;
            
            swap(board[i][j], board[i][j+1]);
        }
    }

    for(int i=0; i<size-1; i++)
    {
        for(int j=0; j<size; j++)
        {
            swap(board[i][j], board[i+1][j]);

            int max=1;
            int maxTmp=1;
            for(int k=0; k<size-1; k++)
            {
                if(board[k][j]==board[k+1][j])
                {
                    maxTmp++;
                }
                else
                {
                    max = maxTmp > max ? maxTmp : max;
                    maxTmp = 1;
                }
            }
            max = maxTmp > max ? maxTmp : max;
            maxTmp = 1;
            
            for(int k=0; k<size-1; k++)
            {
                if(board[i][k]==board[i][k+1])
                {
                    maxTmp++;
                }
                else
                {
                    max = maxTmp > max ? maxTmp : max;
                    maxTmp = 1;
                }
            }
            max = maxTmp > max ? maxTmp : max;
            maxTmp = 1;

            for(int k=0; k<size-1; k++)
            {
                if(board[i+1][k]==board[i+1][k+1])
                {
                    maxTmp++;
                }
                else
                {
                    max = maxTmp > max ? maxTmp : max;
                    maxTmp = 1;
                }
            }
            max = maxTmp > max ? maxTmp : max;
            maxTmp = 1;
            
            ans = max > ans ? max : ans;
            
            swap(board[i][j], board[i+1][j]);
        }
    }

    cout << ans << endl;
    
    return 0;
}

void swap(char *a, char *b)
{
    int tmp=*a;
    *a=*b;
    *b=*a;
}
