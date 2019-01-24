/*
 ============================================================================
 Name        : Test.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void radix(int a[],int n)
{
	int max=a[0],exp=1,i;
	for( i=1;i<n;i++)               //find the max no.
	{
		if(a[i]>max)
			max=a[i];
	}
	while(exp<=max)
	{
		int b[10]={0};
	for( i=0;i<n;i++)               //to get the digit
		b[a[i]/exp%10]++;
	for( i=1;i<10;i++)           //addition of the one's
		b[i]+=b[i-1];
	int *t=(int *)malloc(sizeof(int)*n);
	for(i=n-1;i>=0;i--)             //place elements by subtracting one from the addition of one's to get the next pass
		t[--b[a[i]/exp%10]]=a[i];              
		for(i=0;i<n;i++)        //c from the temporary array to the original array
			a[i]=t[i];
		exp*=10;
		free(t);
	}
}
void main()
{
	int a[]={843,742,113,85,93,47,225};
	int n=7,k;
	radix(a,7);
	for(k=0;k<n;k++)
	printf("%d\t",a[k]);

}
