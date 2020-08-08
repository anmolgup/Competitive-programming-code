#include<stdio.h>



int main()

{

    int l,x=1;

    double s;

    while(x!=0)

    {

        scanf("%d",&l);

        x=l;

        if(x!=0)

        {

            s= (float)(l*l/(2*3.1415926 ));

            printf("%.2f\n",s);

        }

    }







    return 0;

}
