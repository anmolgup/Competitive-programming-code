#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n,m,a,b;
	cin>>n>>m;
	bool arr[m];
	for(int i = 0;i<=m;i++)
		arr[i] = true;
	while(n--)
	{
		cin>>a>>b;
		for(int i = a;i<=b;i++)
			arr[i] = false;
	}
	arr[0] = false;
	vector <int> v;
	for(int i = 1;i<=m;i++)
	{
		if(arr[i])
			v.push_back(i);
	}
	int capacity = v.size();
	cout<<capacity<<endl;
	for(auto i : v)
		cout<<i<<" ";
}