#include<stdio.h>
#include<conio.h>
#define size 10
int front=-1;
int rear=-1;
int a[size];

void insert(int val)
{
 if(front==(rear+1)%size)
 {
 printf("CQ IS FULL");
 }
 else
 {
  if(front==-1)
  {
   front=rear=0;
   a[rear]=val;
  }
  else
  {
  rear=(rear+1)%size;
  a[rear]=val;
  }
 }
}

int rem()
{
 int v;
 if(front ==-1)
 {
  printf("CQ IS EMPTY");
 }
 else
 {
   v=a[front];
   if(front==rear)
   {
   front=rear=-1;
   }
   else
   {
   front=(front+1)%size;
   }
 }
 return v;
}

void display()
{
  int i,j;
  if(front==-1)
  {
   printf("queue is empty");
  }
  else
  {
   for(i=front;i<=rear;i++)
    {
     printf("%d\t",a[i]);
    }
   if(front>rear)
   {
   for(i=front;i<=size-1;i++)
   printf("%d\t",a[i]);
   for(j=0;j<=rear;j++)
   printf("%d\t",a[j]);
   }
  }
 }

void main()
{
 int d,a; clrscr();
 printf("\n1:INSERT\n2:REMOVE\n3:DISPLAY\n4:EXIT\n");
 do{
 printf("\nENTER CHOICE");
 scanf("%d",&d);
 switch(d)
 {
 case 1:printf("\nENTER NOS");
	scanf("%d",&a);
	insert(a);
	break;
 case 2:printf("\nNOS IS %d",rem());
	break;
 case 3:printf("\nNOS IN QUEUE");
	display();
	break;
 case 4:exit();
 }
 }
 while(d!=4);
}
