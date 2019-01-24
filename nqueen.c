#include <stdio.h>
#include <stdlib.h>

void print(int a[20],int n)
{
	int i;
	for (i=0;i<n;i++)
		printf("%d",a[i]);
	printf("\n");
}
int check(int a[20],int r)
{
	int i;
	for(i=0;i<r;i++)
	{
		if(a[i]==a[r]||abs(i-r)==abs(a[i]-a[r]))
			return 0;
	}
	return 1;
}
int nqueen(int a[20],int n,int r)
{
	int i,x=0,y=0;
	for(i=0;i<n;i++)
	{
		a[r]=i;
		if(check(a,r))
		{
			if(r+1<n)
				x+=nqueen(a,n,r+1);
			else
			{
				print(a,n);
				y=1;
			}
		}
	}
	return x+y;
}
int main(void)
{
	int n,a[20],sol;
	printf("Enter the value of n\n");
	scanf("%d",&n);
	sol=nqueen(a,n,0);
	printf("Total solutions are %d\n",sol);
	return 0;
}
