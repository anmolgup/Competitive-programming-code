/* Author 
   Anmol Gupta
*/
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define pb push_back
#define debug(x)  cout<<#x<<" "<<x<<endl;
#define mp make_pair
#define F first
#define S second
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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//printf("%I64d", n)
	ll n,sum1,sum2;
	int ptr1,ptr2;
	cin>>n;
	sum1 = sum2 = 0;
	ll arr[n];
	forr(i,n)
		cin>>arr[i];
	ptr1 = 0;
	ptr2 = n - 1 ;
	if(n == 1) {
		cout<<arr[0]<<"  0\n";
		return 0;
	}
	int i = 1;
	while(ptr1 <=ptr2)
	{
		if(i % 2){

		if(arr[ptr1] < arr[ptr2]){
			sum1 += arr[ptr2];
			ptr2--;
		}
		else
		{
			sum1 += arr[ptr1];
			ptr1++;
		}

		}
		else
		{
			if(arr[ptr1] < arr[ptr2]){
				sum2 += arr[ptr2];
				ptr2--;
			}
			else
			{
				sum2 += arr[ptr1];
				ptr1++;
			}
		}
		i++;
	}
	cout<<sum1<<" "<<sum2<<endl;
}