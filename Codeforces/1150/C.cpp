#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
 
const int N = 1e6 + 5;
 
int n;
int a[N], f[5];
int32_t main()
{
    IOS;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        f[a[i]]++;
    }
    if(f[2] > 0)
    {
        cout << 2 << " ";
        f[2]--;
    }
    if(f[1] > 0)
    {
        cout << 1 << " ";
        f[1]--;
    }
    while(f[2] > 0)
    {
        cout << 2 << " ";
        f[2]--;
    }
    while(f[1] > 0)
    {
        cout << 1 << " ";
        f[1]--;
    }
    return 0;
}