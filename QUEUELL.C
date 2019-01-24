#include<stdio.h>
#include<conio.h>
struct node
{
 int info;
 struct node *next;
};
struct node *front=NULL,*rear=NULL;
void insert(int val)
{
 struct node *n=(struct node*)malloc(sizeof(struct node));
 n->info=val;
 n->next=NULL;
 if(front==NULL)
   front=rear=n;
 else
 {
  rear->next=n;
  rear=n;
 }
}

int rem()
{
 struct node *t=front;
 int v;
 if(front==NULL)
 {
  printf("queue is empty");
  getch();
  exit();
 }
 else
 {
  v=front->info;
  if(front==rear)
   front=rear=NULL;
  else
   front=front->next;
   free(t);
 }
  return v;
}

void display()
{
 struct node *t=front;
 if(front==NULL)
 {
  printf("linked list is empty");
 }
 else
 {
  while(t!=NULL)
  {
   printf("%d\t",t->info);
   t=t->next;
  }
 }
}
void main()
{
 int d,a; clrscr();
 printf("\n1:INSERT\n2:REMOVE\n3:DISPLAY\n4:EXIT\n");
 do{
 printf("ENTER CHOICE\n");
 scanf("%d",&d);
 switch(d)
 {
 case 1:printf("ENTER NOS\n");
	scanf("%d",&a);
	insert(a);
	break;
 case 2:printf("NOS REMOVED IS %d\n",rem());
	break;
 case 3:printf("NOS IN QUEUE\n");
	display();
	break;
 case 4:exit();
 }
 }
 while(d!=4);
 }

