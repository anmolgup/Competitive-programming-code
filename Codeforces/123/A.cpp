#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
char ans[N];
int sieve[N];
#define n_l '\n'
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]: "; cout << to_string(__VA_ARGS__) << endl
template <typename T, size_t N> int SIZE(const T (&t)[N]){ return N; } template<typename T> int SIZE(const T &t){ return t.size(); } string to_string(string s, int x1=0, int x2=1e9){ return '"' + ((x1 < s.size()) ? s.substr(x1, x2-x1+1) : "") + '"'; } string to_string(const char* s) { return to_string((string) s); } string to_string(bool b) { return (b ? "true" : "false"); } string to_string(char c){ return string({c}); } template<size_t N> string to_string(bitset<N> &b, int x1=0, int x2=1e9){ string t = ""; for(int __iii__ = min(x1,SIZE(b)),  __jjj__ = min(x2, SIZE(b)-1); __iii__ <= __jjj__; ++__iii__){ t += b[__iii__] + '0'; } return '"' + t + '"'; } template <typename A, typename... C> string to_string(A (&v), int x1=0, int x2=1e9, C... coords); int l_v_l_v_l = 0, t_a_b_s = 0; template <typename A, typename B> string to_string(pair<A, B> &p) { l_v_l_v_l++; string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; l_v_l_v_l--; return res; } template <typename A, typename... C> string to_string(A (&v), int x1, int x2, C... coords) { int rnk = rank<A>::value; string tab(t_a_b_s, ' '); string res = ""; bool first = true; if(l_v_l_v_l == 0) res += n_l; res += tab + "["; x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v)); auto l = begin(v); advance(l, x1); auto r = l; advance(r, (x2-x1) + (x2 < SIZE(v))); for (auto e = l; e != r; e = next(e)) { if (!first) { res += ", "; } first = false; l_v_l_v_l++; if(e != l){ if(rnk > 1) { res += n_l; t_a_b_s = l_v_l_v_l; }; } else{ t_a_b_s = 0; } res += to_string(*e, coords...); l_v_l_v_l--; } res += "]"; if(l_v_l_v_l == 0) res += n_l; return res; } void dbgs(){;} template<typename Heads, typename... Tails> void dbgs(Heads H, Tails... T){ cout << to_string(H) << " | "; dbgs(T...); }
#define dbgm(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgs(__VA_ARGS__); cout << endl;
int main(){
    string s;
    cin >> s;
    int n = s.size();
     fill(sieve+1, sieve+n+1, 1);
    int sz = 0;
    for(int i = 2;i<=n/2;i++){
        if(sieve[i]){
            for(int j = 1;i*j<=n;j++){
                if(sieve[i*j])
                    sz++;
                sieve[i*j] = 0;
            }
        }
    }
    // dbg(sz);    
    map<char,int> freq;
    for(auto x : s)
        freq[x]++;
    vector<pair<int,char> > v;
    for(auto x : freq)
        v.push_back({x.second,x.first});
    // dbg(v);
    sort(v.begin(),v.end());
    if(v.back().first < sz){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    for(int i = 2;i<=n;++i){
        if(!sieve[i])
            ans[i] = v.back().second;
    }
    int idx = 0;
    for(int i = 1;i<=n;++i){
        if(sieve[i]){
            ans[i] = v[idx].second;
            v[idx].first--;
            if(v[idx].first == 0)
                idx++;
        }
        cout<<ans[i];
    }
    // cout<<ans[3];
}