#inclu
de<stdio.h>
#include<conio.h>
#define s 10
int a[s];
int front=-1;
int rear=-1;
 void insert(int val)
 {
 if(rear==s-1)
 {
 printf("queue is full");
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
  rear++;
  a[rear]=val;
  }
 }
}

int rem()
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
   for(i=front;i<=rear;i++)
   {
   printf("%d\t",a[i]);
   }
 }
}
 void main()
 {
 int d,a; clrscr();
 printf("\n1:INSERT\n2:REMOVE\n3:DISPLAY\n4:EXIT\n");
 do{
 printf("ENTER CHOICE");
 scanf("%d",&d);
 switch(d)
 {
 case 1:printf("\nENTER NOS");
	scanf("%d",&a);
	insert(a);
	break;
 case 2:printf("\nNOS REMOVED IS %d",rem());
	break;
 case 3:printf("\nNOS IN QUEUE");
	display();
	break;
 case 4:exit();
 }
 }
 while(d!=4);
 }


