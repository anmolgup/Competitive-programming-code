#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define ios        	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
ll n,i,j,k,l,t=1,a[100005]={0},m;
vector<ll> prime;	// to store all the prime numbers upto 100000
map<ll,ll> mm;    // to store all the prime number from n to m
void seive()
{
    for(i=2;i<=1e5;i++)  
    {
        if(a[i]==0)     // it means this number is not canceled by any of it's previous number 
        {   prime.pb(i);  // push back it in prime 
            for(j=i*i;j<=1e5;j+=i)
                a[j]=1;  //cancel all it's multiple 
        }
    }
    return;
}
void seg_seive(ll n, ll m)
{
    for(i=0;i<prime.size()&&prime[i]<=m;i++) //one by one from all prime number untill any prime exceeds the upper limit
    {
        for(j=n-(n%prime[i]);j<=m;j+=prime[i]) //n-(n%prime[i]) is done to find just previous multiple
        {									   //of prime i before n
            if(j!=prime[i]) mm[j]=1;   // cut all its multiples excepts itself 
        }
    }
    return;
}
int main()
{   ios
    seive();
	cin>>t;
	while(t--)
    {  cin>>n>>m;
        seg_seive(n,m);
       for(i=max(n,2LL);i<=m;i++)
        if(!mm[i]) cout<<i<<endl; //if i is not canceled it would have default value 0
       cout<<endl;
       mm.clear(); // clear the extra space for each test case
    }
	return 0;
}
