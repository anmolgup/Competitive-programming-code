#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
 
// #define fisier 1
 
using namespace std;
 
typedef long long ll;
 
const int mod = 1000000007;
const double dancila = 3.14159265359; // PI 
const double eps = 1e-9;
 

int ps[40002];
ll a, b;

ll cnt(ll xx)
{
	return 1LL * ps[a*b-1] * (xx/(a*b)) + ps[xx%(a*b)];
}
int main()
{
 
    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
	int t;
	cin >> t;
	for(; t; --t)
	{
		ll q;
		cin >> a >> b >> q;
		for(int i = 0; i < a*b; ++i)
		{
			if(i == 0)
				ps[i] = 0;
			else
			{
				int va = ((i%a)%b);
				int vb = ((i%b)%a);
				ps[i] = ps[i-1];
				if(va != vb)
					++ps[i];
			}
		}
		for(; q; --q)
		{
			ll l, r;
			cin >> l >> r;
			if(a == b)
				cout << 0 << " ";
			else
				cout << cnt(r) - cnt(l-1) << " ";
		}
		cout << '\n';
	}
    return 0;
}