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
void inorder(NODE *p)
{
	NODE *s[50];int top=-1;
	while(1)
	{
		while(p!=NULL)
		{
			s[++top]=p;

			p=p->left;
		}
		if(top!=-1)
		{
			p=s[top--];
			printf("%d\t",p->data);
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
	inorder(root);
}
