#include <stdio.h>
#include <stdlib.h>

	void merge(int a[],int low,int mid,int high)
	{
		int *t=(int *)malloc(sizeof(int)/(high-low+1));
		int i=low,j=mid+1,k=0;
		while(i<=mid && j<=high)
		t[k++]=a[i]<a[j]?a[i++]:a[j++];
		while(i<=mid)
			t[k++]=a[i++];
		while(j<=high)
			t[k++]=a[j++];
		for(k=0,i=low;i<=high;i++,k++)
			a[i]=t[k];
	}

void mergesort(int a[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}
void main()
{
	int a[]={843,742,113,85,93,47,225};
	int n=7,k;
	mergesort(a,0,7);
	for(k=1;k<n+1;k++)
	printf("%d\t",a[k]);
}
