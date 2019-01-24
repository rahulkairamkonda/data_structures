#include<stdio.h>
#include<conio.h>
#define size 10
int a[size];
int topa=-1;
int topb=size;
void pusha(int val)
{
 if(topa==topb-1)
 {
 printf("stack is full");
 }
 else
 {
 topa++;
 a[topa]=val;
 }
}

void pushb(int val)
{
 if(topb == topa+1)
 {
  printf("stack is full");
 }
 else
 {
  topb--;
  a[topb]=val;
 }
}

int popa()
{
 int v;
 if(topa==-1)
 {
 printf("stack is empty");
 }
 else
 {
 v=a[topa];
 topa--;
 }
 return v;
}

int popb()
{
 int v;
 if(topb==size)
 {
 printf("stack is empty");
 }
 else
 {
 v=a[topb];
 topb++;
 }
 return v;
}

void displaya()
{
 int i;
 if(topa==-1)
 {
 printf("stack is empty");
 }
 else
 {
  for(i=topa;i>=0;i--)
  {
   printf("%d\t",a[i]);
  }
 }
}

void displayb()
{
 int i;
 if(topb==size)
 {
   printf("stck is sempty");
 }
 else
 {
 for(i=topb;i<size;i++)
 {
 printf("%d\t",a[i]);
 }
 }
}
void main()
{
int d,x,y;clrscr();
do
{
printf("\n1:PUSH A \n2: PUSH B \n3:POP A \n4: POP B \n5:DISPLAY A \n6:DISPLAY B \n7:EXIT");
printf("\nENETR CHOICE");
scanf("%d",&d);

switch(d)
{
case 1:printf("enter value for stack a");
       scanf("%d",&x);
       pusha(x);
       break;
case 2:printf("enter value for stcak b");
       scanf("%d",&y);
       pushb(y);
       break;
case 3:printf("deleted value from a is =  %d",popa());
       break;
case 4:printf("deleted value from b is = %d",popb());
       break;
case 5:printf(" values of a :");
       displaya();
       break;
case 6:printf(" values of b :");
       displayb();
       break;
case 7:exit();
       break;
}
}
while(d!=7);
}
