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
double area(int x1, int y1, int x2, int y2, 
                            int x3, int y3) 
{ 
    return abs(((x1 * (y2 - y3) )+ (x2 * (y3 - y1)) +  
                (x3 * (y1 - y2))) / 2.0); 
} 
bool check(int x1, int y1, int x2, int y2, int x3,  
             int y3, int x4, int y4, int x, int y) 
{ 
    /* Calculate area of rectangle ABCD */
    double A = area(x1, y1, x2, y2, x3, y3) +  
              area(x1, y1, x4, y4, x3, y3); 
  	// debug(A);
    /* Calculate area of triangle PAB */
    double A1 = area(x, y, x1, y1, x2, y2); 
  	// debug(A1);
    /* Calculate area of triangle PBC */
    double A2 = area(x, y, x2, y2, x3, y3); 
  	// debug(A2);
    /* Calculate area of triangle PCD */
    double A3 = area(x, y, x3, y3, x4, y4); 
  	// debug(A3);
    /* Calculate area of triangle PAD */
    double A4 = area(x, y, x1, y1, x4, y4); 
  	// debug(A4);
  	double total = A1 + A2 + A3 + A4;
    /* Check if sum of A1, A2, A3 and A4  
       is same as A */
    return (A == total); 
} 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//printf("%I64d", )
	ll d,n,m;
	cin>>n>>d>>m;
	int f1,f2,f3,f4,f5,f6,f7,f8;
	f1 = 0;
	f2 = d;
	while(m--)
	{
		ll t1,t2;
		cin>>t1>>t2;
		if(check(0,d,d,0,n,n-d,n-d,n,t1,t2) == true)
		{
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}	
}