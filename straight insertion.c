#include<stdlib.h>
#include<stdio.h>
void main()
{
	int a[100],i,j,t,k,n;
	printf("enter no. of elements");
	scanf("%d",&n);
	printf("enter the elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<n;i++)
	{
		t=a[i];
		for(j=i;j>=1&&a[j-1]>t;j--)
		{
		  a[j]=a[j-1];
		}
		a[j]=t;
		printf("\nthe elements after %d pass are ",i);
		for(k=0;k<n;k++)
		{
			printf("%d\t",a[k]);
		}
	}
}
