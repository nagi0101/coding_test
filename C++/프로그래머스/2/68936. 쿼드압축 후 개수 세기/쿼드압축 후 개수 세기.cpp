#include <string>
#include <vector>

using namespace std;

void q(vector<vector<int>>& arr, vector<int>& answer, 
       size_t xfrom, size_t xto, 
       size_t yfrom, size_t yto)
{   
    bool eq = true;
    int m = arr[xfrom][yfrom];
    for(size_t x = xfrom; x < xto; ++x)
    {
        for(size_t y = yfrom; y < yto; ++y)
        {
            if(arr[x][y] != m)
            {
                eq = false;
                break;
            }
        }
    }
    if(eq)
    {
        ++answer[m];
        return;
    }
    
    size_t xmed = (xfrom + xto) / 2;
    size_t ymed = (yfrom + yto) / 2;
    
    size_t xs[] = {xfrom, xmed};
    size_t xe[] = {xmed, xto};
    size_t ys[] = {yfrom, ymed};
    size_t ye[] = {ymed, yto};
    for(size_t i = 0; i < 2; ++i)
    for(size_t j = 0; j < 2; ++j)
        q(arr, answer, xs[i], xe[i], ys[j], ye[j]);

}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer{0, 0};
    q(arr, answer, 0, arr[0].size(), 0, arr.size());
    return answer;
}