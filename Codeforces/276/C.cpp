#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>
#define MAX_N 300001
using namespace std;
typedef long long lld;

int n,q,x,y;
lld ret = 0LL;

lld niz[MAX_N];
lld new_niz[MAX_N];

lld tree[MAX_N];
void update(int x, lld val)
{
    while (x <= n)
    {
        tree[x] += val;
        x += (x & -x);
    }
}
lld read(int x)
{
    int sum=0;
    while (x>0)
    {
        sum+=tree[x];
        x -= (x & -x);
    }
    return sum;
}

int main()
{
    scanf("%d%d",&n,&q);
    for (int i=0;i<n;i++) scanf("%I64d",&niz[i]);
    sort(niz,niz+n);
    while (q--)
    {
        scanf("%d%d",&x,&y);
        update(x,1);
        update(y+1,-1);
    }
    for (int i=1;i<=n;i++)
    {
        new_niz[i-1] = read(i);
        //printf("%d. %d\n",i, new_niz[i-1]);
    }
    sort(new_niz,new_niz+n);
    for (int i=n-1;i>=0;i--)
    {
        ret += niz[i] * new_niz[i];
    }
    cout << ret << endl;
    return 0;
}