/*
 ============================================================================
 Name        : sort123.c
 Author      : sort
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int split(int a[],int low, int high)
{
	int t;
	int p=a[low];
	int l=low+1;
	int r=high;

	while(1)
	{
		while(l<=high && p>a[l])
			l++;
		while(p<a[r])
			r--;
		if(l<r)
		{
			t=a[l];
			a[l]=a[r];
			a[r]=t;
		}
		else
		{
			a[low]=a[r];
			a[r]=p;
			break;
		}
	}
	return r;
}
void quick(int a[],int low,int high)
{
	int p;
	if(low<high)
	{

		p=split(a,low,high);
		quick(a,low,p-1);
		quick(a,p+1,high);
	}
}
void main()
{
	int i;
	int a[8]={1,9,4,5,23,29,2,83};
	quick(a,0,7);
	for(i=0;i<8;i++)
		printf("%d\t",a[i]);
}
