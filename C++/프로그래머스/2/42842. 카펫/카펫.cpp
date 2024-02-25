#include <vector>
#include <cmath>

#define MAX_S (2'000)

using namespace std;

vector<int> solution(int brown, int yellow) {
    int mins = sqrt(brown + yellow);
    vector<int> answer;
    for(int i = mins; i < MAX_S; ++i)
    {
        for(int j = 3; j <= mins; ++j)
        {
            int a = i * j;
            int b = (i + j) * 2 - 4;
            int y = a - b;
            if(b == brown && y == yellow)
            {
                answer = { i, j };
                goto end;
            }
        }
    }    
end:
    
    return answer;
}