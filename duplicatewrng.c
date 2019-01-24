#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}NODE;

void add(NODE**p,int v)
	{
	NODE *newnode,*temp;
	newnode=(NODE *)malloc(sizeof(NODE));
	newnode->data=v;
	newnode->next=NULL;
	if(*p==NULL)
		*p=newnode;
	else
	{
      temp=*p;
      while(temp->next!=NULL)
      {
    	  temp=temp->next;
      }
      temp->next=newnode;
	}
	}
void display(NODE *p)
 {
	 while(p!=NULL)
	 {
		 printf("%d\t",p->data);
		 p=p->next;
	 }
	 printf("\n");
 }
void duplicate(NODE *p)
{
	NODE *temp=p,*prev;
	while(p!=NULL)
	{
		prev=p;
		for(temp=p->next;temp!=NULL;temp=temp->next)
		{
			if(temp->data==p->data);
			{
				prev->next=temp->next;
				free(temp);
				temp=prev;
			}
			prev=temp;
		}
			p=p->next;
	}
}
void main()
{
	 NODE *first=NULL;
	 add(&first,10);
	 add(&first,50);
	 add(&first,60);
	 add(&first,10);
	 add(&first,70);
	 add(&first,50);
	 display(first);
	 duplicate(first);
	 display(first);
}

