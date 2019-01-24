#include<stdio.h>
#include<conio.h>
struct node
{
 int info;
 struct node *next;
};
struct node *list=NULL;

void insertbeg(int val)
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

void insertend(int val)
{
 struct node*t=list;
 struct node*n=(struct node*)malloc(sizeof(struct node));
 n->info=val;
 n->next=NULL;
 if(list==NULL)
  list=n;
 else
 {
  while(t->next!=NULL)
  t=t->next;
  t->next=n;
  n->next=NULL;
 }
}

int deletebeg()
{
 int v;
 struct node*t=list;
 if(list==NULL)
 {
  printf("\nlinked list is empty");
  getch();
 }
 else
 {
  v=t->info;
  if(t->next==NULL)
  list=NULL;
  else
  list=t->next;
  free(t);
 }
 return v;
}

int deleteend()
{
 int v;
 struct node*t=list;
 struct node*p=NULL;
 if(list==NULL)
 {
 printf("linked list is empty");
 getch();
 }
 else
 {
  if(t->next==NULL)
  {
   v=t->info;
   list=NULL;
  }
  else
  {
   while(t->next!=NULL)
   {
    p=t;
    t=t->next;
   }
   v=t->info;
   p->next=NULL;
   free(t);
 }}
 return v;
}

int deleteafter(int pos)
{
 int i,v;
 struct node*t=list;
 struct node*p=NULL;

 if(list==NULL)
 {
  printf("linked list is empty");
  getch();
 }
 else
 {
  for(i=1;i<=pos;i++)
  {
  p=t;
  t=t->next;
  }
 v=t->info;
 p->next=t->next;
 free(t);
 }
 return v;
}

void insertafter(int pos,int val)
{ int i;
  struct node*t=list;
  struct node*p=NULL;
  struct node*n=(struct node*)malloc(sizeof(struct node));
  n->info=val;
  for(i=1;i<=pos;i++)
  {
   p=t;
   t=t->next;
  }
  p->next=n;
  n->next=t;
}

void search(int v)
{
 int i=1;
 struct node*t=list;
 if(list==NULL)
 {
  printf("linked list is empty");
 }

  while(t!=NULL)
  {
   if(v==t->info)
   {
    printf("%d@POS%d",v,i);
    getch();break;
    }
    else
    {
    t=t->next;
    i++;
    }
   }
     if(t==NULL)
     printf("element is not there");
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
void main()
{
 int d,a,b,c,e,r,n;
 do{
 printf("\n1:INSERT BEG\n2:INSERT END\n3:INSERT AFTER\n4:DELETE BEG\n5:DELETE END\n6:DELETE AFTER\n7:SEARCH\n8:DISPLAY\n9:EXIT\n");
 scanf("%d",&d);
 switch(d)
 {
  case 1: printf("\n enter value");
	  scanf("%d",&a);
	  insertbeg(a);
	  break;

  case 2: printf("\n enter value");
	  scanf("%d",&b);
	  insertend(b);
	  break;

  case 3: printf("\n enter value of pos and val");
	  scanf("%d",&e,&c);
	  insertafter(e,c);
	  break;

  case 4: printf("\ndeleted value at beg is = %d",deletebeg());
	  break;

  case 5: printf("\ndeleted value at end is = %d",deleteend());
	  break;

  case 6: printf("\nenter pos for delete after\n");
	  scanf("%d",&r);
	  printf("deleted value is = %d",deleteafter(r));
	  break;

  case 7: printf("\nenetr value to find position");
	  scanf("%d",&n);
	  search(n);
	  break;

  case 8: display();
	  break;
  case 9: exit();

  }
  }
  while(d!=9);
  }














