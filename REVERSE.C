#include<stdio.h>
#include<conio.h>
struct node
{
 int info;
 struct node *next;
};
struct node *list=NULL;
struct node *list1=NULL;

void copy2()
{
struct node*p=NULL;
struct node*t=list;
while(t!=NULL)
{
  struct node*n=(struct node*)malloc(sizeof(struct node));
  n->info=t->info;
  n->next=NULL;
  if(list1==NULL)
  {
  list1=n;
  p=n;
  }
  else
  {
  p->next=n;
  p=n;
  }
  t=t->next;
}

 list=list1;
}


void copy()
{

 struct node*t=list;
 struct node*temp=NULL;
 while(t!=NULL)
 {
   struct node*n=(struct node*)malloc(sizeof(struct node));
   n->info=t->info;
   n->next=NULL;
   if(list1==NULL)
    {
   // n->next=NULL;
    list1=n;
    }

    else
    {
    temp=list1;
     while(temp->next!=NULL)
       temp=temp->next;
     temp->next=n;

     }


      t=t->next;
     }
   list=list1;
 }
void insert(int val)
{
struct node*n=(struct node*)malloc(sizeof(struct node));
 n->info=val;
 if(list==NULL)
 {
  n->next=NULL;
  list=n;
 }
 else
 {
  n->next=list;
  list=n;
 }
}

void display()
{
 struct node*t=list;
 if(list==NULL)
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

 int count()
{
 int c=0;
 struct node*t=list;
 if(list==NULL)
 {
  printf("linked list is empty");
 }
 else
 {
  while(t!=NULL)
  {
   c=c+1;
   t=t->next;
  }
 }
 return c;
}

void rev()
{
 struct node*t=list;
 struct node*temp=NULL;
 struct node*p=NULL;
 while(t!=NULL)
 {
  temp=p;
  p=t;
  t=t->next;
  p->next=temp;
  }
  list=p;

}

void main()
{
 int d,a;  clrscr();
 do{
 printf("\n1:INSERT \n2:COUNT\n3:REVERSE\n4:DISPLAY\n5:COPY\n6:EXIT");
 printf("7:cpy2\n");
 scanf("%d",&d);
 switch(d)
 {
  case 1: printf("\n enter value");
	  scanf("%d",&a);
	  insert(a);
	  break;
  case 2: printf("count =%d",count());
	  break;
  case 3: rev();
	  printf("reverse done!!!");
	  break;
  case 4: display();
	  break;
  case 5: copy();
	  printf("copy done!!!");
	  break;

  case 6: exit();
  case 7: copy2();
	  printf("copy2 done!!!");
	  break;
 }
}
while(d!=6);
}



