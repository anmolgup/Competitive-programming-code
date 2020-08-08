#include<stdio.h>
int main()
{
	int str,t,counter=0;
	scanf("%d %d",&str,&t);
	int arr[t][2];
	for(int i=0;i<t;i++)
		scanf("%d %d ",&arr[i][0],&arr[i][1]);
	//printf("strength%d ",str);
	/*for(int i=0;i<t;i++)
		printf("array%d %d \n",arr[i][0],arr[i][1]);
	*/
	for(int i=0;i<t;i++)
	{
		for(int j=0;j<t;j++)
		{
			if(arr[j][0]>arr[j+1][0])
			{
				 int temp = arr[j][0];
				 arr[j][0] = arr[j+1][0];
				 arr[j+1][0] = temp;
				 temp = arr[j][1];
				 arr[j][1] = arr[j+1][1];
				 arr[j+1][1]= temp;
			}
		}
	}
	/*for(int i=0;i<t;i++)
		printf("%d %d \n",arr[i][0],arr[i][1]);
	*/
	for(int i=0;i<t;i++)
	{
		if(arr[i][0]<str)
			str += arr[i][1];
		else 
		{
			counter++;
			break;
		}
		//printf("anmol%d ",str);
	}
	if(counter == 0)
		printf("YES\n");
	else
		printf("NO\n");
}