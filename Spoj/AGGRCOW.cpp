#include <bits/stdc++.h>
using namespace std;
int N,C;
long long A[100005];
bool chk(long long dist)
{
	long long last=A[0];
	int cnt=1;
	for(int i=1; i<N; i++){
		if((A[i]-last)>=dist){
			cnt++;
			last=A[i];
		}
	}
	if(cnt>=C)return true;
	return false;
}
void solve()
{
	cin>>N>>C;
	for(int i=0; i<N; i++)cin>>A[i];
	sort(A,A+N);
	long long low=0; long long high = 1000000000;
	int mid; int pos=0;
	while(high>=low)
	{
		mid=(high+low)/2;
		if(chk(mid)){
			low=mid+1;
			pos=mid;
		}
		else{
			high = mid-1;
		}
	}
	cout<<pos<<endl;
}
int main()
{
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
