#include <iostream>
#include <limits.h>

#define MAX_N (1'000'002)

static int dp[MAX_N];

int main()
{
    int N;
    std::cin >> N;

    for(size_t i = 0; i < MAX_N; ++i)
    {
        dp[i] = INT_MAX;
    }

    dp[1] = 0;
    for(size_t i = 1; i < N; ++i)
    {
        dp[i + 1] = std::min(dp[i + 1], dp[i] + 1);
        if(i * 2 < MAX_N) dp[i * 2] = std::min(dp[i * 2], dp[i] + 1);
        if(i * 3 < MAX_N) dp[i * 3] = std::min(dp[i * 3], dp[i] + 1);
    }

    std::cout << dp[N] << std::endl;

    return 0;
}
