#include <iostream>

using namespace std;

int main() 
{
    int input;
    cin>>input;

    int ans = 0;

    for(int i=input; i>input-55; i--)
    {
        int sum = i;
        
        int t=i;
        while(t > 0)
        {
            sum += t % 10;
            t /= 10;
        }
        
        if(sum == input)
        {
            ans = i;
        }
    }

    cout << ans<<endl;
    
    return 0;
}