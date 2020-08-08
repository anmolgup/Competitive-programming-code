#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int> sequence;
	string s,t;
	cin>>s>>t;
	int arr[26] = {0};
	for(int i = 0;i<n;i++)
	{
		arr[s[i] - 'a']++;
		arr[t[i] - 'a']--;
	}
	for(int i = 0;i<26;i++)
	{
		if(arr[i])
		{
			cout<<"-1"<<endl;
			return 0;
		}
	}
	int i,j;
	for(i = 0;i<n;i++)
	{
		if(s[i]!=t[i])
	 	{
			for(j =i +1;j<n;j++)
			{
				if(s[j]==t[i])
					break;
			}
			// cout<<j<<endl;
			for(int k = j-1;k>=i;k--)
			{
				swap(s[k],s[k+1]);
				// cout<<s<<endl;
				sequence.push_back(k+1);
			}
		} 
	}
	if(sequence.size()==0)
		cout<<"0"<<endl;
	else 
	{
	cout<<sequence.size()<<endl;
	for(auto i : sequence)
		cout<<i<<" ";
	}
}