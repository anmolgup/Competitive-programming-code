#include<stdio.h>
#include<string.h>
int main()
{
	int len;
	int def[26]={0};
	char arr[100];
	scanf("%s",arr);
	len =strlen(arr);
	if(len==4)
	{
		int q=0,w=0,e=0,r=0;
		for(int i=0;i<4;i++)
		{
			if(arr[i]==82)
				q++;
			else if(arr[i]==66)
				w++;
			else if(arr[i]==89)
				e++;
			else if(arr[i]==71)
				r++;
			if(!q)
				def[17]++;
			else if(!w)
				def[1]++;
			else if(!e)
				def[24]++;
			else if(!r)
				def[6]++;
		}

	}
	else
{
	for(int i=0;i<len;i++)
		{
		if(arr[i]=='!')
		{
			if(i-4>=0)
				def[(arr[i-4]-'A')]++;
			else
				def[arr[i+4]-'A']++;
			arr[i];
		}
		}
}
	printf("%d %d %d %d\n",def[17],def[1],def[24],def[6]);


}