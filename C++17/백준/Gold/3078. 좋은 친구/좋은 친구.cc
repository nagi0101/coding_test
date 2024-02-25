#include <iostream>
#include <queue>

using namespace std;

const int MAX_N = 300001;

int N, K;
queue<int> arr[21];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long ans = 0;
    cin >> N;
    cin >> K;
    for(int i = 0; i < N; ++i)
    {
        char name[21];
        cin >> name;
        int l = 0;
        while (name[l] != '\0')
        {
            ++l;
        }

        queue<int> *q = &arr[l];
        while(!q->empty() && i - q->front() > K) q->pop();
        ans += q->size();
        q->push(i);
    }

    cout << ans << '\n';

    return 0;
}