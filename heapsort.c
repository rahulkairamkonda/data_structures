#include<stdio.h>
#include<stdlib.h>

void heapify(int a[],int p,int n)    // construction
{
	int t=a[p],i;                    // t has last node which is calculated using (n/2)-1

	for(i=(2*p)+1;i<n;i=(2*i)+1)     //2p+1 is for moving to left node
	{
		if((i+1)<n && a[i]<a[i+1])   //checks if left node is smaller than right node if true then "i" is now greatest
			i++;
		if(a[i]>t)                   // greatest is compared t
			a[(i-1)/2]=a[i];
		else
			break;
	}
	a[(i-1)/2]=t;                    // dropping takes places
}
void heapsort(int a[],int n)   //reconstruction
{
	int i,t;
	for(i=(n/2)-1;i>=0;i--)       //used for construction of max heap
	 heapify(a,i,n);

	for(i=n-1;i>0;i--)
	{
		t=a[0];                  // 0 index is swapped always coz it is max with the last index
		a[0]=a[i];
		a[i]=t;
		heapify(a,0,i);          // property of max heap of 0 th index element changes thus it is heapified
 	}
}
void main()
{
	int a[100],i,n;
	printf("enter nos of elements");
	scanf("%d",&n);
	printf("\nenter elements");
	for(i=0;i<n;i++)
	  scanf("%d",&a[i]);
	heapsort(a,n);
	printf("\nsorted:");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
}
