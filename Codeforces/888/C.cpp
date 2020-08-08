#include<bits/stdc++.h>
using namespace std;
vector<char> v;
int size;
bool check(int star, int k, char a){
	if((int)star>=(int)(size-1)){
		return true;
	}
	int temp = star+1;
	while(temp!=size && v[temp]!=a){
		temp++;
	}
	int compare=temp-star-1;
	if(compare<k){
		return check(temp,k,a);
	}
	else{
		return false;
	}
}
int binaryS(int start, int end, char a){
	if(start>end){
		return start;
	}
	int mid = (start+end)/2;
	bool ans = check(-1, mid, a);
	if(ans){
		return binaryS(start,mid-1, a);
	}
	else{
		return binaryS(mid+1,end, a);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	char a[100005];
	cin>>a;
	for(int i=0;a[i]!='\0';i++){
		v.push_back(a[i]);
	}
	size = (int)(v.size());	
	if(size==1){
		cout<<1<<endl;
		return 0;
	}
	int max=99999999;
	for(int i=97;i<=122;i++){
		int ans=binaryS(1,size,(char)i);
		if(ans==size+1){
			ans=size;
		}
		if(ans<max){
			max=ans;
		}
	}
	cout<<max<<endl;
	return 0;
}