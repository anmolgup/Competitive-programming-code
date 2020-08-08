#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define vec vector<ll>
#define ms multiset<ll>
#define pr pair<ll,ll>
#define f(i,x,n) for(i=x;i<n;i++)
#define int long long
#define mod 1000000007
 int mul[1000001];
 int fr[1000001];
ll max(ll a,ll b)
{
  if(a>b)
    return a;
  else return b;
}
void fastio()
{
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
main()
{   
    fastio();
    vector<pair<int,int>>vc;
    vector<pair<int,int>>ans;
    int aaa=0;
    int i;
    for(i=0;i<3;i++)
    {
      int a,b;
      cin >> a >> b;
      vc.pb(mp(a,b));
    }
    sort(vc.begin(),vc.end());



    for(i=vc[0].first;i<=vc[1].first;i++)
    { 
      ans.pb(mp(i,vc[0].second));
      aaa++;

    }

    if(vc[1].second>=vc[0].second){
    for(i=vc[0].second;i<=vc[1].second;i++)
    {
      ans.pb(mp(vc[1].first,i));
      aaa++;

    }}
    else
    {for(i=vc[0].second;i>=vc[1].second;i--)
    {
      ans.pb(mp(vc[1].first,i));
      aaa++;

    }}


    if(vc[2].second>=vc[1].second){
    for(i=vc[1].second;i<=vc[2].second;i++)
    {
      ans.pb(mp(vc[1].first,i));
      aaa++;

    }}
    else
    {for(i=vc[1].second;i>=vc[2].second;i--)
    {
      ans.pb(mp(vc[1].first,i));
      aaa++;

    }}


      for(i=vc[1].first;i<=vc[2].first;i++)
    {
      ans.pb(mp(i,vc[2].second));
      aaa++;

    }
    
    sort(ans.begin(),ans.end());
    for(i=1;i<ans.size();i++)
    {
         if(ans[i].first==ans[i-1].first && ans[i].second==ans[i-1].second)
          aaa--;
    }
    cout << aaa << endl;
     cout <<ans[0].first << " " << ans[0].second << endl;
    for(i=1;i<ans.size();i++)
    {
         if(ans[i].first==ans[i-1].first && ans[i].second==ans[i-1].second)
          {continue;

            
          }
          else
            cout <<ans[i].first << " " << ans[i].second << endl;

    }

}