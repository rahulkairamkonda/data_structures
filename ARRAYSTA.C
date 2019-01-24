#include<stdio.h>
#include<conio.h>
#define size 10
int a[size];
int top=-1;
void push(int value)
{
 if(top==size-1)
 {
 printf("stack is full");
 }
 else
 {
 top++;
 a[top]=value;
 }
}
int pop()
{
int v;
 if(top==-1)
 {
 printf("stack is empty");
 getch();
 }
 else
 {
 v=a[top];
 top--;
 }
return v;
}
int peek()
{
int c;
 if(top==-1)
 {
 printf("stack is empty");
 getch();
 }
 else
 {
 c=a[top];
 }
return c;
}
void display()
{
int i;
 if(top==-1)
 {
 printf("stack is empty");
 }
 else
 {
 for(i=top;i>0;i--)
 printf("%d \t",a[i]);
 }
}
void main()
{

 int d,a; clrscr();
 do{
 printf("\n 1:push \n 2:pop \n 3:peek \n 4:display \n 5:exit");
 printf("\n enter choice");
 scanf("%d",&d);
 switch(d)
 {
 case 1:printf("enter val to be entered\n");
	scanf("%d",&a);
	push(a);
	break;
 case 2:printf("deleted value is\n%d",pop());

	 break;
 case 3:printf("top value is\n%d",peek());
	break;
 case 4:printf("values are\n");
	display();
	break;
 case 5: exit();
	 break;
 default:printf("wrong choice");
	 break;
}
}
while(d!=5);
}







