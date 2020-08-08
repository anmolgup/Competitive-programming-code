#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	char arr[100];
	cin >> arr;
	int b=strlen(arr);

	int lower=0;
	int upper=0;
	for (int i=0;i<=b-1;i++)
	{
		int a=(int)arr[i];
		if ((a>=65)&&(a<=90))
		{
			upper++;
		}
		else
		{
			lower++;
		}
	}

	if (upper>lower)
	{
		for (int i=0;i<=b-1;i++)
		{
			int a;
			a=(int)arr[i];
			if((a>=97)&&(a<=122))
			{
				a=a-32;
				cout << (char)a;
			}
			else
			{
				cout << arr[i];
			}
		}
	}
	else
	{
		for (int i=0;i<=b-1;i++)
		{
			int a;
			a=(int)arr[i];
			if ((a>=65)&&(a<=90))
			{
				a=a+32;
				cout << (char)a;
			}
			else
			{
				cout << arr[i];
			}
		}
	}

	cout << endl;
	return 0;
}