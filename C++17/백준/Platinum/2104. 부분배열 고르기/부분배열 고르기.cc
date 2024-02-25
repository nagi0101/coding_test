#include <iostream>
#include <algorithm>

using namespace std;

long long int key(long long  int A[], long long  int N, long long  int i, long long  int j)
{
    if(i==j)
    {
        return A[i] * A[i];
    }
    
    long long int mid = (i + j) / 2;
    long long int result = max(key(A, N, i, mid), key(A, N, mid+1, j));

    long long int l=mid, r=mid, minh=A[mid];
    long long int rs=A[mid];
    while(r-l <= j-i)
    {
        long long int qh = i < l ? min(minh, A[l-1]) : minh;
        long long int ph = r < j ? min(minh, A[r+1]) : minh;

        long long int qs = i < l ? rs + A[l-1] : rs;
        long long int ps = r < j ? rs + A[r+1] : rs;
        
        long long int q = qs * qh;
        long long int p = ps * ph;

        if(q > p)
        {
            l--;
            minh=qh;
            rs=qs;
        }
        else
        {
            r++;
            minh=ph;
            rs=ps;
        }
        result = max(result, max(p, q));
    }
    return result;
}

int main()
{
    long long int A[100000];
    long long int N;
    long long int i, j;

    cin >> N;
    for(int i=0; i<N; i++)
        cin >> A[i];
    
    long long int r = key(A, N, 0, N-1);

    cout << r << endl;
    
    return 0;
}