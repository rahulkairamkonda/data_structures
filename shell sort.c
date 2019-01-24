#include<stdlib.h>
#include<stdio.h>
void main()
{
	int a[100],i,j,t,k,n,g;
	printf("enter no. of elements");
	scanf("%d",&n);
	printf("enter the elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
for(g=n/2;g>=1;g=g/2)
{
	for(i=g;i<n;i++)
	{
		t=a[i];
		for(j=i;j>=g && a[j-g]>t;j-=g)
			a[j]=a[j-g];
		a[j]=t;
	}
		printf("\nthe elements after %d pass are ",i);
		for(k=0;k<n;k++)
		{
			printf("%d\t",a[k]);
		}
	}
}
