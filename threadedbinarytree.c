#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *left,*right;
	int leftflag,rightflag;
}NODE;

void insertTBT(NODE **p, int v){
	NODE *newnode = (NODE*)malloc(sizeof(NODE));
	NODE *temp;
	newnode->data = v;
	newnode->leftflag = 0;
	newnode->rightflag = 0;

	if(*p == NULL){
		newnode->right = NULL;
		newnode->left = NULL;
		*p = newnode;
	}

	else
	{
		temp = *p;

		while(1){
			if(temp->data > v && temp->leftflag)
				temp = temp->left;
			else if(temp->data < v && temp->rightflag)
				temp = temp->right;
			else
				break;
		}
		if (temp->data < v){
			newnode->right = temp->right;
			temp->right = newnode;
			temp->rightflag = 1;
			newnode->left = temp;
		}
		else{
			newnode->left = temp->left;
			temp->left = newnode;
			temp->leftflag = 1;
			newnode->right = temp;
		}
	}
}

void display(NODE *p){
	while(1){
		while(p->leftflag)
			p = p->left;
		printf("%d\t",p->data);

	while(!p->rightflag){
		p = p->right;
		if(p == NULL)
			return;
		printf("%d\t",p->data);
	}
	p = p->right;
	}

}

int main(void){
	NODE *root;
	insertTBT(&root,10);
	insertTBT(&root,12);
	insertTBT(&root,15);
	insertTBT(&root,25);
	insertTBT(&root,50);
	insertTBT(&root,75);
	insertTBT(&root,65);
	insertTBT(&root,60);

	display(root);

}

