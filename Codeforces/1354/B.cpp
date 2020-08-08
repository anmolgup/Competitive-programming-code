#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

using namespace std;
string st;

bool isValid(int k)
{
	int ar[4] = {0};
	for(int i=0;i<k-1;i++)
	{
		int idx = st[i] - '0';
		ar[idx]++;
	}
	
	for(int i=k-1;i<st.size();i++)
	{
		int idx = st[i] - '0';
		ar[idx]++;
		
		if((ar[1] > 0) && (ar[2] > 0) && (ar[3] > 0))
		return true;
		
		idx = st[i-k+1] - '0';
		ar[idx]--;
	}
	
	return false;
}

int getAns()
{
	int res = INF;
	int L = 3;
	int R = st.size();
	
	while(L <= R)
	{
		int mid = (L + R) / 2;
		
		if(isValid(mid))
		res = min(res , mid) , R = mid-1;
		else
		L = mid + 1;
	}
	
	if(res == INF) return 0;
	else		   return res;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>st;
		cout<<getAns()<<endl;
	}
}