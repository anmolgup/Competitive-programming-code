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
	string t,str;
	int len;
	char temp;
	cin>>t>>str;
	len = t.length();
	sort(t.begin(),t.end());
	int i = 0;
	// cout<<t[i]<<endl;
	if(t[0] == '0')
	{
		for(int j = 1;j<len;j++)
			{
				if(t[j] != '0')
				{
					temp = t[i];
					t[i] = t[j];
					t[j] = temp;
					break;
				}
			}
	}
	// cout<<t<<endl;
	if(str == t)
		cout<<"OK\n";
	else
	{
		cout<<"WRONG_ANSWER\n";
	}
}