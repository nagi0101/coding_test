#include <iostream>

static int M[1001];

int main()
{
    int N;
    std::cin >> N;

    M[1] = 1;
    M[2] = 2;
    for(size_t i = 3; i <= N; ++i)
    {
        M[i] = (M[i-1] + M[i-2]) % 10'007;
    }

    std::cout << M[N] << std::endl;

    return 0;
}