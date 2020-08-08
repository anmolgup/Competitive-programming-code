#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds; 
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define MX              200005
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
 
int32_t main()
{
    c_p_c();
    int n,u; cin>>n>>u;
    mk(arr,n,int);
 
    for(int i=0;i<n;++i)
        cin>>arr[i];
 
    int num=0,den=1,got=0;
 
    for(int i=0;i<n-2;++i)
    {
        int id = upper_bound(arr+i,arr+n,arr[i]+u) - arr;
        id--;
 
        if(id-i+1>=3)
        {
            /*if(i==3)
            {
                cout<<(arr[id]-arr[i+1])<<' '<<(arr[id]-arr[i])<<'\n';
            }*/
            got=1;
            if(num*(arr[id]-arr[i])<den*(arr[id]-arr[i+1]))
                num = arr[id]-arr[i+1],den=arr[id]-arr[i];
        }
    }
 
    if(!got)
        cout<<-1<<'\n';
 
    else
    {
        double ans = num;
        ans = ans*1.0;
 
        ans /= (double)den;
 
        cout<<ps(ans,10)<<'\n';
    }
    return 0;
}