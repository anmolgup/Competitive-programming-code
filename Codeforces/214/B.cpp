#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define INF 2000000000
#define MOD 1000000007
#define ll long long
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define si set<int>
#define msi map<string,int>
#define REP(i,a,b) for(int i=int(a);i<=int(b);i++)
#define TRvi(c,it) for(vi::iterator it=(c).begin();it!=(c).end();it++)
#define TRvii(c,it) for(vii::iterator it=(c).begin();it!=(c).end();it++)
#define TRmsi(c,it) for(msi::iterator it=(c).begin();it!=(c).end();it++)
 
using namespace std;
 
int main()
{
    IOS;
    int n;
    cin >> n;
    vector<int>arr;
    vector<int>digs;
    ll sum=0;
    multiset<int>freq[3];
    REP(i,0,n-1)
    {
        int x;
        cin >> x;
        if(x%3==0)
            digs.push_back(x);
        else
            sum+=x;
        freq[x%3].insert(x);
    }
    if(sum%3==0)
    {
        if(!freq[1].empty())
        {
            for(auto it=freq[1].begin();it!=freq[1].end();it++)
                digs.push_back((*it));
        }
        if(!freq[2].empty())
        {
            for(auto it=freq[2].begin();it!=freq[2].end();it++)
                digs.push_back((*it));
        }
    }
    else if(sum%3==1)
    {
        if(freq[1].size()>=1)
            freq[1].erase(freq[1].begin());
        else
        {
            int i=0;
            while(!freq[2].empty()&&i<2)
            {
                freq[2].erase(freq[2].begin());
                i++;
            }
        }
        if(!freq[1].empty())
        {
            for(auto it=freq[1].begin();it!=freq[1].end();it++)
                digs.push_back((*it));
        }
        if(!freq[2].empty())
        {
            for(auto it=freq[2].begin();it!=freq[2].end();it++)
                digs.push_back((*it));
        }
    }
    else if(sum%3==2)
    {
        if(freq[2].size()>=1)
            freq[2].erase(freq[2].begin());
        else
        {
            int i=0;
            while(!freq[1].empty()&&i<2)
            {
                freq[1].erase(freq[1].begin());
                i++;
            }
        }
        if(!freq[1].empty())
        {
            for(auto it=freq[1].begin();it!=freq[1].end();it++)
                digs.push_back((*it));
        }
        if(!freq[2].empty())
        {
            for(auto it=freq[2].begin();it!=freq[2].end();it++)
                digs.push_back((*it));
        }
    }
    sort(digs.begin(),digs.end());
    if(digs[0]!=0||digs.empty())
    {
        cout << -1;
        return 0;
    }
    else
    {
        if(digs[digs.size()-1]==0)
            cout << 0;
        else
        {
            for(int i=digs.size()-1;i>=0;i--)
                cout << digs[i];
        }
    }
 
}