/******************************************
* NICK : nikhilsinghh59 *
******************************************/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define watch(x) cout << (#x) << " is " << (x) << endl
#define endl "\n"

#define PB push_back
#define F first
#define S second
#define all(c) (c).begin(),(c).end()
const int M = 1e9+7;

ll parent[200006];
ll size[200006];

void make_set(int v) {
    for(int i=0 ; i<v; i++) {
        parent[i]=i;
        size[i] = 1;
    }
}

ll find_set(ll v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

bool check(string s , ll k) {

    ll i=0 , j = s.length()-1;

    while(i < j) {
        if(s[i]!=s[j]) {
            return false;
        }
        i++;
        j--;
    }

    for(ll i=0 ; i<k ; i++) {
        for(ll j=i+k ; j<s.length() ; j+=k) {
            if(s[i]!=s[j]) {
                return false;
            }
        }
    }

    return true;

}

int main()
{   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll t;
    cin >> t;

    while(t--) {
        ll n,k;
        cin >> n >> k;

        //ll ans=0;

        string s;
        cin >> s;

        make_set(n);

        ll ar[n];

        if(check(s , k)) {
            cout << 0 << endl;
            continue;
        }

        //vector<ll>adj[n+1];
        for(ll i=0 ; i<k ; i++) {
            for(ll j=i+k ; j<n ; j+=k) {
                //ar[j]=i;
                union_sets(i , j);
            }
        }


        ll i=0 , j = n-1;

        while(i < j) {
            union_sets(i , j);
            i++;
            j--;
        }

        pair<ll ,ll>p[n];

        for(ll i=0 ; i<n ;i++) {
            ar[i] = find_set(i);
            p[i] = {ar[i] , i};
        }
        sort(p , p+n);
        map<char , ll>mp;

        mp[s[p[0].second]]++;

        ll mx=-1;
        ll ans=0;

        // for(ll i=0 ; i<n ; i++) {
        //     cout << p[i].first << "  " << p[i].second << endl;
        //     cout << size[p[i].first] << endl;
        // }

        for(ll i=1 ; i<n ; i++) {
            if(p[i].first!=p[i-1].first) {
                ans+=(size[p[i-1].first] - mx);
                mp.clear();
                mx=-1;
                mp[s[p[i].second]]++;
                mx = max(mx , mp[s[p[i].second]]);
            }
            else {
                mp[s[p[i].second]]++;
                mx = max(mx , mp[s[p[i].second]]);
            }
        }

        if(p[n-1].first == p[n-2].first) {
            ans+=(size[p[n-1].first] - mx);
        }

        cout << ans << endl;
        

    }
    
    return 0;
}