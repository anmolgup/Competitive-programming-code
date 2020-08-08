#include<bits/stdc++.h>
 
using namespace std;
 
#define sc(a) scanf("%lld",&a)
 
typedef long long ll;
 
const int MAX = 5e3 + 11;
 
ll a[22];
ll pro[22];
 
int main()
{
    for(int i=0;i<14;++i)
        sc(a[i]);
 
    ll res = 0;
 
    for(int i=0;i<14;++i)
    {
        for(int j=0;j<14;++j)
            pro[j] = a[j];
        ll tmp = pro[i];
        pro[i] = 0;
        for(int j=0;j<14;++j)
            pro[j] += tmp/14;
        tmp %= 14;
        int k = i+1;
        while(tmp--)
        {
            if(k == 14)
                k = 0;
            pro[k++]++;
        }
        ll score = 0;
        for(int j=0;j<14;++j)
        {
            if(pro[j] & 1)
                continue;
            score += pro[j];
        }
        res = max(res,score);
    }
 
    cout<<res;
 
 
    return 0;
}