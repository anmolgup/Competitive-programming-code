 
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
 
char s[10010];
 
ll dp[6110][6110];
 
ll solve(ll i, ll j)
{
    if (i == j || i > j)
        return 0;
 
    if (dp[i][j] != -1)
        return dp[i][j];
 
    if (s[i] == s[j])
    {
        dp[i][j] = solve(i+1, j-1);
    }
    else
    {
        dp[i][j] = min(solve(i+1, j), solve(i, j-1)) + 1;
    }
    return dp[i][j];
}
 
int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, m, n;
 
    sl(n);
 
    while(n--)
    {
        ss(s);
 
        memset(dp, -1, sizeof(dp));
 
        cout << solve(0, strlen(s)-1) << endl;
    }
 
    return 0;
}
