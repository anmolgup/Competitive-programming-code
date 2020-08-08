#include<iostream>
#include <unordered_map>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin>>n;

	unordered_map<string,int> map;

	for(int i=0;i<n;i++){
		string s; cin>>s;
		map[s]++;
	}
	string winner;
	int win_score=0;
	for(auto i: map){
		if(i.second>win_score){
			win_score=i.second;
			winner=i.first;
		}
	}

	cout<<winner;

	return 0;
}