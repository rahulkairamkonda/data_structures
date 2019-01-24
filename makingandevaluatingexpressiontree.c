#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *left,*right;
}NODE;
int EvalExpTree(NODE *p)
{
	if(p==NULL)
		return 0;
	else
	if(p->left==NULL && p->right==NULL)
		return p->data;
	else
	{
		int x=EvalExpTree(p->left);
		int y=EvalExpTree(p->right);
		int z;
		switch(p->data)
		{
		case '+':
						z=x+y;
						break;
		case '-':
						z=x-y;
						break;
		case '*':
						z=x*y;
						break;
		case '/':
						z=x/y;
						break;
		}
		return z;
	}
}
char* MakeExpTree(NODE **p,char *exp)
{
	char*q,v;
	if(*exp=='\0')
		return NULL;
	else
	{
		NODE *newnode=(NODE *)malloc(sizeof(NODE));
		if((*exp>='0' && *exp<='9'))
			v=*exp-48;
		else
			v=*exp;
				newnode->data=v;
				newnode->left=NULL;
				newnode->right=NULL;
				*p=newnode;
				if(!(*exp>='0' && *exp<='9'))
				{
					q=MakeExpTree(&newnode->left,exp+1);
					q=MakeExpTree(&newnode->right,q+1);
					return q;
				}
				return exp;
	}
}
void inorder(NODE *p)
{
	if(p==NULL)
		return;
	if(p->left==NULL&&p->right==NULL)
		printf("%d",p->data);
	else
	{
		inorder(p->left);
		printf("%c",p->data);
		inorder(p->right);
	}
}
void main()
{
NODE *root=NULL;
int ans;
char ch[20];
printf("enter an expression to be evaluated");
scanf("%s",ch);
MakeExpTree(&root,ch);
ans=EvalExpTree(root);
inorder(root);
printf("the ans is %d",ans);
}
