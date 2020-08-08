#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
using namespace std;

const int MOD = 1000000007;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    
    for (char x : s)
    {
        if (x == 'w' || x == 'm')
        {
            cout << 0 << '\n';
            return 0;
        }
    }
    
    int n = s.size();
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        dp[i] = dp[i - 1];
        if (s[i - 1] == s[i - 2] && (s[i - 1] == 'u' || s[i - 1] == 'n'))
            dp[i] = (dp[i] + dp[i - 2]) % MOD;
    }
    
    cout << dp[n] << '\n';
    
    return 0;
}