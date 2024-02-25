#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    sort(begin(s), end(s), [](auto a, auto b){ return a > b; });
    return s;
}