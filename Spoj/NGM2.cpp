#include <bits/stdc++.h>

using namespace std;

// definitions
#define FOR(i,a,b) for( int i=(a),_n=(b); i<=_n; ++i )
#define clr(x,v) memset( x, v, sizeof(x) )

typedef long long ll;
typedef vector<ll> VLL;

// declarations
ll n, m;
VLL num;

// functions
void input( void )
{
	ll v;
	num.clear();
	
	FOR( i, 1, m ) {
		scanf( "%lld", &v );
		num.push_back( v );
	}
}

inline ll gcd( ll a, ll b )
{
	return ( b ? gcd(b,a%b):a );
}

inline ll lcm( ll a, ll b )
{
	return (a/gcd(a,b))*b;
}

void solve( void )
{
	ll ans = n;
	ll stt = (1<<m)-1;
	ll val;
	int cnt;

	FOR( i, 1, stt ) {
		cnt = 0;
		val = 1;
		FOR( j, 0, m-1 ) {
			if( (i&(1<<j)) ) {
				val = lcm( val, num[j] );
				++cnt;
			}
		}

		val = n/val;

		if( cnt&1 ) 
			val = -val;

		ans += val;
	}

	printf( "%lld\n", ans );
}

// main function
int main( void )
{

	// input
		scanf( "%lld%lld", &n, &m ); 
		input();
		solve();
	
	return 0;
