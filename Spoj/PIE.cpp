/*  
   By Anmol Gupta :)
*/
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define pb push_back
#define debug(x)  cout<<#x<<" "<<x<<endl;
#define mp make_pair
#define ff first
#define ss second
#define allunique(v) 	v.erase(unique(v.begin(),v.end()),v.end());
#define endl "\n"
#define MOD 1000000007
#define MOD9 1000000009
#define gc getchar_unlocked
#define ms(s, n) memset(s, n, sizeof(s))
#define prec(n) fixed<<setprecision(n)
#define eps 0.000001
#define pll pair<ll,ll>
#define all(v) v.begin(), v.end()
#define bolt ios::sync_with_stdio(0)
#define forr(i,n) for(ll i=0;i<n;i++)
#define eof (scanf("%d" ,&n))!=EOF
typedef long long ll;
using namespace std;
double f;
int n;
double arr[10004];
bool ischeck(double num,double brr[])
{
	double curr,temp;
	curr = 0;
	// for(int i = 0;i<n;i++)
		// debug(brr[i]);
	if(num == 0)
		return false;
	for (int i=0; i<n; i++)
        curr+=(int)(brr[i]/num);
    if (curr>=f)
        return 1;
    else
        return 0;
}
int main()
{
	double pi = acos(-1.0);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//printf("%I64d", n)
	// cout<<pi<<endl;
	ll t;
	cin>>t;
	while(t--)
	{
		cin>>n>>f;
		f++;
		double l,h,ans,mid;
		l = h = 0;
		forr(i,n){
			cin>>arr[i];
			arr[i] = pi*arr[i]*arr[i];
			h += arr[i];
		}
		sort(arr,arr + n);	
		ans = 200;
		// for(int i = 0;i<n;i++)
		// debug(h);
		while(h - l >= 1e-6)
		{
			mid = l + (h-l)/2;
			// debug(mid);
			if(ischeck(mid,arr) == true)
			{
				ans = mid;
				l = mid;
			}
			else
			{
				h = mid;
			}
		}
		// debug(l);
		// debug(h);
		cout<<setprecision(8)<<ans<<endl;
	}

}
