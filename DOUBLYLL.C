#include<stdio.h>
#include<conio.h>
struct node
{
 int info;
 struct node *next;
 struct node *pre;
};
struct node *list=NULL;

void insertbeg(int val)
{
 struct node*n=(struct node*)malloc(sizeof(struct node));
 n->info=val;
 n->pre=NULL;
 if(list==NULL)
 {
  n->next=NULL;
  list=n;
 }
 else
 {
  n->next=list;
  list->pre=n;
  list=n;
 }
}

void insertend(int val)
{
  struct node*n=(struct node*)malloc(sizeof(struct node));
  struct node*t=list;
  n->info=val;
  n->next=NULL;
  if(list==NULL)
  {
   n->pre=NULL;
   list=n;
  }
  else
  {
    while(t->next!=NULL)
    {
     t=t->next;
    }
     t->next=n;
     n->pre=t;
  }
}

int deletebeg()
{
  struct node*t=list;
  int v;

  if(list==NULL)
  {
   printf("list is empty");
  }
  else
  {
   if(list->next==NULL)
   {
    v=list->info;
    list=NULL;
   }
   else
   {
    v=t->info;
    list=list->next;
    list->pre=NULL;
   }
   free(t);
  }
  return v;
}

int deleteend()
{
 struct node *t=list;
 int v;
  if(list==NULL)
  {
   printf("list is empty");
  }
  else
  {
   if(list->next==NULL)
   {
    v=list->info;
    list=NULL;
   }
   else
   {
    while(t->next!=NULL)
     {
     t=t->next;
     }
     v=t->info;
     t->pre->next=NULL;
    }
    free(t);
  }
  return v;
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
  }   printf("\n");
 }
}

void deleteval(int val)
{
 struct node *t=list;
 if(list==NULL)
 printf("ll is empty");
 else
 {
  while(t!=NULL)
  {
   if(val==t->info)
   {
     if(t==list)
     {
      list=t->next;
      list->pre=NULL;
      free(t);
      break;
     }
     else if(t->next==NULL)
     {
      t->pre->next=NULL;
      free(t);
      break;
     }
     else
     {
      (t->pre)->next=t->next;
      (t->next)->pre=t->pre;
      free(t);
      break;
     }
   }
   else
   {
    t=t->next;
   }
  }
 }
}


void main()
{
 int a,b,r,d;  clrscr();
 do{
 printf(" 1:INSERT BEG\n 2:INSERT END\n 3:DELETE BEG\n 4:DELETE END\n 5:DELETE VALUE\n 6:DISPLAY\n 7:EXIT\n");
 printf("enter choice\n");
 scanf("%d",&d);
 switch(d)
 {
  case 1: printf("enter value\n");
	  scanf("%d",&a);
	  insertbeg(a);
	  display();
	  break;

  case 2: printf("enter value\n");
	  scanf("%d",&b);
	  insertend(b);
	  display();
	  break;

  case 3: printf("deleted value at beg is = %d\n",deletebeg());  display();
	  break;

  case 4: printf("deleted value at end is = %d\n",deleteend()); display();
	  break;

  case 5: printf("enter value to be deleted\n");
	  scanf("%d",&r);
	  deleteval(r);   display();
	  break;

  case 6: display();
	  break;
  case 7: exit();

  }
  }
  while(d!=7);
  }















