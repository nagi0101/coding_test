#include <iostream>

using namespace std;

int main()
{
    int N;
    int M;
    char B[50][50];
    for(int i = 0; i < 50; ++i)
    {
        for(int j = 0; j < 50; ++j)
        {
            B[i][j] = -1;
        }
    }

    cin >> N;
    cin >> M;
    for(int i = 0; i < N; ++i)
    {
        cin >> B[i];
    }

    int r = 100;
    for(int i = 0; i < N - 8 + 1; ++i)
    {
        for(int j = 0; j < M - 8 + 1; ++j)
        {
            // B[i][j]에서 시작
            int wc = 0; // 왼쪽 위 W일 때 새로 칠하는거
            int bc = 0; // 왼쪽 위 B일 때 새로 칠하는거
            for(int n = 0; n < 8; ++n)
            {
                for(int m = 0; m < 8; ++m)
                {
                    int no = !(n % 2); // 첫째 줄
                    int mo = !(m % 2); // 첫째 열
                    char b = B[i + n][j + m];
                    if(no)
                    {
                        if(mo) // 첫째 줄, 첫째 열
                        {
                            if(b == 'W')
                            {
                                ++bc;
                            }
                            else
                            {
                                ++wc;
                            }
                        }
                        else // 첫째 줄, 둘째 열
                        {
                            if(b == 'W')
                            {
                                ++wc;
                            }
                            else
                            {
                                ++bc;
                            }
                        }
                    }
                    else
                    {
                        if(mo) // 둘째 줄, 첫째 열
                        {
                            if(b == 'W')
                            {
                                ++wc;
                            }
                            else
                            {
                                ++bc;
                            }
                        }
                        else // 둘째 줄, 둘째 열
                        {
                            if(b == 'W')
                            {
                                ++bc;
                            }
                            else
                            {
                                ++wc;
                            }
                        }
                    }
                }
            }
            int mc = wc < bc ? wc : bc;
            r = r < mc ? r : mc;
        }
    }
    cout << r << endl;

    return 0;
}