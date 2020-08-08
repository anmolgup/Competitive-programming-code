#include<bits/stdc++.h>
#define pb push_back
#define debug(x)  cout<<#x<<" "x<<endl;
#define mp make_pair
#define F first
#define S second
#define endl "\n"
#define MOD 1000000007
#define MOD9 1000000009
#define gc getchar_unlocked
#define ms(s, n) memset(s, n, sizeof(s))
#define prec(n) fixed<<setprecision(n)
#define eps 0.000001
#define all(v) v.begin(), v.end()
#define bolt ios::sync_with_stdio(0)
#define forr(i,p,n) for(ll i=p;i<n;i++)
#define eof (cin>>n)!=EOF
typedef long long ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//printf("%I64d", n)
		ll n,flagpos,flagneg,minvalue,sum;
		cin>>n;
		flagneg = flagpos = 0;
		sum = 0;
		minvalue = INT_MAX;
		ll slime;
		// ll arr[n];
		for(int i =0;i<n;i++)
		{
				cin>>slime;
				if(slime>0)
					flagpos = 1;
				if(slime<0)
					flagneg = 1;
				sum += abs(slime);
				minvalue = min(minvalue, abs(slime)); 
		}
		if(n == 1)
			cout<<slime<<endl;
		else
		{
			if(flagpos && flagneg)
			{
				// cout<<"here"<<endl;
				cout<<sum<<endl;
			}
			else
			{
				// cout<<sum<<endl;
				cout<<(sum - (2*minvalue))<<endl;
			}
		}

}