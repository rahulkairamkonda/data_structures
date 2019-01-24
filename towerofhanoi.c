#include <stdio.h>
#include <stdlib.h>

int tower(int n,char s,char a,char t)
{
	if(n==1)
		{
		printf("Shift %d from %c to %c\n",n,s,t);
		return 1;
		}
	else
	{
	int x=tower(n-1,s,t,a);
		printf("Shift %d from %c to %c\n",n,s,t);
	int y=tower(n-1,a,s,t);
	return x+y+1;
	}
}
int main (void)
{
	int n,total;
	printf("Enter the no of disks\n");
	scanf("%d",&n);
	total=tower(n,'A','B','C');
	printf("Total %d\n",total);
	return 0;
}
