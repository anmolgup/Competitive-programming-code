#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int n;
string s;

int main()
{
    cin >> s;
    ll ans = 1;
    if(s.length()!=1)
    {
    for(ll i=s.length()-1;i>0;--i)
    {
        ans+=(10-(s[i]-'0'+1));
    }
    ans+=9;
    cout << ans;
    }
    else
    {
        cout << 9;        
    }
    
}