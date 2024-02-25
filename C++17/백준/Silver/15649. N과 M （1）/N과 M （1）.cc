#include <iostream>
#include <sstream>

#define MAX_N (8)

static bool visited[MAX_N + 1];
static std::stringstream s;

static int v[MAX_N];
static int n, m;

void dfs(int count)
{
    if(count == m)
    {
        for(int i = 0; i < m; ++i)
        {
            s << v[i] << " ";
        }
        s << '\n';
        return;
    }
    for(size_t i = 1; i <= n; ++i)
    {
        if(visited[i])
        {
            continue;
        }
        visited[i] = true;
        v[count] = i;
        dfs(count + 1);
        visited[i] = false;
    }
}

int main(void)
{
    std::cin >> n >> m;
    dfs(0);

    std::cout << s.str();

    return 0;
}