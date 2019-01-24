#include<stdio.h>
#include<conio.h>
#define size 10
int front=-1;
int rear=-1;
int a[size];
void insertend(int val)
{
 if(rear == size-1)
 {
 printf("Q is full");
 }
 else
 {
  if(front == -1)
  {
   front=rear=0;
   a[rear]=val;
  }
  else
  {
  rear++;
  a[rear]=val;
  }
 }
}

int deletebeg()
{
int v;
 if(front==-1)
 {
 printf("Queue is empty");
 getch();   exit();
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
  front++;
  }
 }
 return v;
}

void display()
{
 int i;
 if(front==-1)
 {
 printf("queue is empty");
 }
 else
 {
 printf("\nNOS IN QUEUE");
   for(i=front;i<=rear;i++)
   {
   printf("%d\t",a[i]);
   }
 }
}
void insertbeg(int val)
{
int i;
 if(rear==size-1 && front ==0)
 {
 printf("DQ is full");
 }
 else
 {
  if(front==-1)
  {
   front=rear=0;
   a[front]=val;
  }
  else
  {
   if(front==0)
   {
    for(i=rear;i>=0;i--)
    {
     a[i+1]=a[i];
    }
    a[0]=val;
    rear++;
   }
   else
   {
   front--;
   a[front]=val;
   }
  }
 }
}
void main()
 {
 int d,a,b; clrscr();
 printf("\n2:INSERT beg\n1:INSERT END\n3:DELETE \n4:DISPLAY\n5:EXIT\n");
 do{
 printf("\nENTER CHOICE");
 scanf("%d",&d);
 switch(d)
 {
 case 1:printf("\nENTER NOS");
	scanf("%d",&a);
	insertend(a);
	display();
	break;
 case 2:printf("\nENTER NOS");
	scanf("%d",&b);
	insertbeg(b);
	display();
	break;

 case 3:printf("\nNOS REMOVED FROM END IS %d",deletebeg());
       display();
	break;
 case 4:printf("\nNOS IN QUEUE");
	display();
	break;
 case 5:exit();
 }
 }
 while(d!=5);
 }