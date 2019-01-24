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
	int ch;
	printf("insert %d\t",v);
	if(*p==NULL)
	{
		NODE *newnode=(NODE *)malloc(sizeof(NODE));
		newnode->data=v;
		newnode->left=NULL;
		newnode->right=NULL;
		*p=newnode;
	}
	else
	{
		printf("enter 1.left 2.right of %d\n",(*p)->data);
		scanf("%d",&ch);
		if(ch==1)
			insertBT(&(*p)->left,v);
		else
			insertBT(&(*p)->right,v);
	}
}
void preorder(NODE *p)
{
	NODE *s[50];int top=-1;
	while(1)
	{
		while(p!=NULL)
		{
			s[++top]=p;
			printf("%d\t",p->data);
			p=p->left;
		}
		if(top!=-1)
		{
			p=s[top--];
			p=p->right;
		}
		else
			break;
	}
}
void main()
{
	NODE *root=NULL;
	insertBT(&root,50);
	insertBT(&root,75);
	insertBT(&root,60);
	insertBT(&root,65);
	insertBT(&root,15);
	printf("\n");
	preorder(root);
}
