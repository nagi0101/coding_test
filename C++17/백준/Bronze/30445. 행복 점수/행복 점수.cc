#include <iostream>
#include <cstdio>
#include <map>

#define MAX_W (80)
#define MAX_C (20)
#define MAX_S (MAX_W * MAX_C + MAX_W)

using namespace std;

char happy[] = { 'H', 'A', 'P', 'Y' };
char sad[] = { 'S', 'A', 'D' };

int main(void)
{
    char s[MAX_S + 2];
    cin.getline(s, MAX_S + 1);

    map<char, int> m;
    for(char c = 'A'; c <= 'Z'; ++c) { m[c] = 0; }
    for(char* c = s; *c != '\0'; ++c) { ++m[*c]; }

    int hp = 0, sp = 0;
    for(char c: happy) { hp += m[c]; }
    for(char c: sad) { sp += m[c]; }

    printf("%d.", (hp + sp) == 0 ? 50 : (hp * 100 / (hp + sp)) );
    printf("%02d\n", (hp + sp) == 0 ? 0 : ((hp * 10000 + ((hp + sp) / 2)) / (hp + sp)) % 100);

    return 0;
}
