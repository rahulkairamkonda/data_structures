/*
 ============================================================================
 Name        : binary.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *left,*right;
}NODE;
void insertBT(NODE **p,int v)
{
	if(*p==NULL)
	{
		NODE *newnode=(NODE *)malloc(sizeof(NODE));
		newnode->data=v;
		newnode->left=NULL;
		newnode->right=NULL;
		*p=newnode;
	}
	else if(v>(*p)->data)
		insertBT(&(*p)->right,v);
	else
		insertBT(&(*p)->left,v);
}
int postorder(NODE *p)
{
	int c=0;
	NODE *s[50];int top=-1,flag[50];
	while(1)
	{
		while(p!=NULL)
		{
			c++;
			s[++top]=p;
			flag[top]=0;
			p=p->left;
		}
		if(flag[top]==0)
		{
			flag[top]=1;
			p=s[top];
			p=p->right;
		}
		else
		{
			while(top!=-1 && flag[top])
			{
				printf("%d\t",s[top--]->data);

			}
		}
		if(top==-1)
			break;
	}
	return c;
}
void main()
{
	int c;
	NODE *root=NULL;
	insertBT(&root,50);
	insertBT(&root,40);
	insertBT(&root,90);
	insertBT(&root,10);
	insertBT(&root,45);
	insertBT(&root,80);
	insertBT(&root,15);
	insertBT(&root,43);
	insertBT(&root,70);
	insertBT(&root,47);
	insertBT(&root,85);
	printf("\n");
	c=postorder(root);
	printf("the count is %d\t",c);
}

