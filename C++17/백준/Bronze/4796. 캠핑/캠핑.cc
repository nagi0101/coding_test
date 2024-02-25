#include <iostream>
#include <vector>

using namespace std;

typedef struct 
{
    int L;
    int P;
    int V;
} TEST_CASE;

int main()
{
    vector<TEST_CASE> cases;

    while(true)
    {
        TEST_CASE testcase;
        cin >> testcase.L;
        cin >> testcase.P;
        cin >> testcase.V;

        if(!(testcase.L || testcase.P || testcase.V))
            break;
        
        cases.push_back(testcase);
    }

    for(int i=0; i<cases.size(); i++)
    {
        int q = (cases[i].V / cases[i].P) * cases[i].L;
        int r = (cases[i].V % cases[i].P) < cases[i].L ? (cases[i].V % cases[i].P) : cases[i].L;
        int ans = q+r;
        cout << "Case " << i+1 << ": " << ans << endl;
    }
    
    return 0;
}