#include <iostream>
#include <cstdarg>

typedef struct
{
    int l=1;
    int s;
} CUBE;

using namespace std;

int min(int n, ...)
{
    int result;
    va_list vl;

    va_start(vl, n);
    result=va_arg(vl, int);
    for(int i=0; i<n-1; i++)
    {
        int next=va_arg(vl, int);
        result = result < next ? result : next;
    }
    va_end(vl);

    return result;
}

long long int put(int l, int w, int h, CUBE cubes[], int &n)
{
    if(l==0 || w==0 || h==0)
        return 0;
    
    int r;

    int minl=min(3, l, w, h);

    CUBE *maxc=NULL;
    for(int i=0; i<n; i++)
    {
        if(cubes[i].s <= 0)
            continue;
        if(cubes[i].l > minl)
            break;
        maxc=&cubes[i];
    }
    
    if(!maxc)
    {
        return -1;
    }
    
    maxc->s--;

    long long res1 = put(l-maxc->l, w, h, cubes, n);
    long long res2 = put(maxc->l, w-maxc->l, h, cubes, n);
    long long res3 = put(maxc->l, maxc->l, h-maxc->l, cubes, n);

    if(res1==-1 || res2==-1 || res3==-1)
        return -1;

    return 1+res1+res2+res3;
}

int main(void)
{
    long long ans = -1;
    int l, w, h;
    int n;
    
    cin >> l;
    cin >> w;
    cin >> h;
    
    cin >> n;

    CUBE *cubes = new CUBE[n];
    
    for(int i=0; i<n; i++)
    {
        int p;
        cin >> p;
        for(int k=0; k<p; k++)
        {
            cubes[i].l *= 2;
        }
        cin >> cubes[i].s;
    }

    ans=put(l, w, h, cubes, n);

    cout << ans << endl;
    
    delete []cubes;
    
    return 0;
}

    
