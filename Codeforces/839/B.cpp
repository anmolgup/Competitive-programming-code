
#include <bits/stdc++.h>
using namespace std;
int n, k, have[5], cnt[5];
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    have[2] = 2 * n, have[4] = n;
    for(int i = 0; i < k; i++){
        int x;
        cin >> x;
        while(x >= 3)
            if(have[4] > 0)
                x -= 4, have[4]--;
            else if(have[2] > 0)
                x -= 2, have[2]--;
            else
                return cout << "NO" << '\n', 0;
        if(x > 0)
            cnt[x]++;
    }
    while(cnt[2])
        if(have[2] > 0)
            cnt[2]--, have[2]--;
        else if(have[4] > 0)
            cnt[2]--, have[4]--, have[1]++;
        else
            cnt[2]--, cnt[1] += 2;
    if(cnt[1] > have[1] + have[2] + have[4] * 2)
        return cout << "NO" << '\n', 0;
    cout << "YES" << '\n';
    return 0;
}