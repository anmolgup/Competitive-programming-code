#include<iostream>
#include <vector>
#include <string>
using namespace std;
 
// bool is_adjacent(vector<string> v,int i,int j,char ch ){	//is ch present in neighbourhood
	// if(i==0 && j==0) return true;
 
	// if(i==0) return (v[i][j-1]==ch);
	// if(j==0) return (v[i-1][j]==ch);
 
	// return (v[i-1][j]==ch || v[i][j-1]==ch);
// }
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);\
	cout.tie(NULL);
 
	int n,m; cin>>n>>m;
	vector<string> v;
 
	for(int i=0;i<n;i++){
		string s; cin>>s;
		v.push_back(s);
	}
	string s="WB";
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(v[i][j]=='.'){
				v[i][j]=s[(i+j)%2];
			}
		}
	}
 
	for(auto i:v){
		cout<<i<<endl;
	}
 
	return 0;
}