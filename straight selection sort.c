#include<stdlib.h>
#include<stdio.h>
void main()
{
	int a[100],i,j,t,k,n,m;
	printf("enter no. of elements");
	scanf("%d",&n);
	printf("enter the elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++)
	{
		m=i;
		for(j=m+1;j<n;j++)
		{
			if(a[j]<a[m])
				m=j;
		}
		t=a[i];
		a[i]=a[m];
		a[m]=t;
		printf("\nthe elements after %d pass are ",i);
		for(k=0;k<n;k++)
		{
			printf("%d\t",a[k]);
		}
	}
}
