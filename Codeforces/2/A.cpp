#include<iostream>
#include<map>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
#define abs(x) ((x)>0?(x):-(x))
#define M 1000000007
#define lld signed long long int
#define pp pop_back()
#define ps(x) push_back(x)
#define tkint(n) scanf("%d",&n)
#define tkchar(ch) scanf("%c",&ch)
#define tklong(n) scanf("%I64d",&n)
struct nn
{
    string s;
    int sc;
}data[1001];
int main()
{
    map<string,int>mp,nmp,done;
    int n;
    string ans;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>data[i].s>>data[i].sc;
        mp[data[i].s]+=data[i].sc;
    }
    int mx=-1000*1000-5;
    for(int i=1;i<=n;++i)
        if(mx<mp[data[i].s])mx=mp[data[i].s];
    for(int i=1;i<=n;++i)
    {
        nmp[data[i].s]+=data[i].sc;
        if(mx==mp[data[i].s]&&mx<=nmp[data[i].s]){ans=data[i].s;break;}
    }
    cout<<ans;
}