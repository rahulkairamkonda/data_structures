#include<stdio.h>
#include<conio.h>
#define size 10
int front=-1;
int rear=-1;
int a[size];
void insert(val)
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

int deleteend()
{
 int v;
 v=a[rear];
 if(front==rear)
 {
  front=rear=-1;
 }
 else
 {
 rear--;
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
   for(i=front;i<=rear;i++)
   {
   printf("%d\t",a[i]);
   }
 }
}


void main()
 {
 int d,a; clrscr();
 printf("\n1:INSERT\n2:DELETE BEG\n3:DELETE END\n4:DISPLAY\n5:EXIT\n");
 do{
 printf("\nENTER CHOICE");
 scanf("%d",&d);
 switch(d)
 {
 case 1:printf("\nENTER NOS");
	scanf("%d",&a);
	insert(a);
	break;
 case 2:printf("\nNOS REMOVED FROM BEG IS %d",deletebeg());
	break;
 case 3:printf("\nNOS REMOVED FROM END IS %d",deleteend());
	break;
 case 4:printf("\nNOS IN QUEUE");
	display();
	break;
 case 5:exit();
 }
 }
 while(d!=5);
 }