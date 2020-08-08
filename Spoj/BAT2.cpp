#include <stdio.h>
#include <iostream>
#include <climits>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <vector>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <utility>
#include <queue>
 
using namespace std;
 
#define ll long long
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pii pair <int, int>
#define pll pair <int, int>
#define plp pair <int, pll >
#define pb push_back
 
ll a[103], n;
 
ll dp[104][104][104];
 
ll solve(ll i, ll in, ll de)
{
    if (i > n + 1)
        return 0;
 
    if (dp[i][in][de] != -1)
        return dp[i][in][de];
 
    dp[i][in][de] = solve(i + 1, in, de);
 
    if (a[i] > a[in])
        dp[i][in][de] = max(dp[i][in][de], solve(i + 1, i, de) + 1);
 
    if (a[i] < a[de])
        dp[i][in][de] = max(dp[i][in][de], solve(i + 1, in, i) + 1);
 
//    cout << i << " " << in << " " << de << " " << dp[i][in][de] << endl;
 
    return dp[i][in][de];
}
 
int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, m;
 
    sl(t);
 
    for (cs = 1; cs <= t; cs++)
    {
        sl(n);
 
        for (i = 2; i <= n + 1; i++)
        {
            sl(a[i]);
        }
 
        a[0] = -LLONG_MAX;
        a[1] = LLONG_MAX;
 
        memset(dp, -1, sizeof(dp));
 
        printf("%lld\n", solve(2, 0, 1));
    }
 
    return 0;
