/*
 ============================================================================
 Name        : HuffmanTree.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct Pnode
{
	char a[10];
	int freq;
}Pnode;

typedef struct node
{
	Pnode data;
	struct node *next;
}node;

void insert(node **p,char *ch,int fr)
{
	node *temp=*p,*prev;
	node *newnode=(node *)malloc(sizeof(node));
    newnode->data.freq=fr;
    strcpy(newnode->data.a,ch);
	newnode->next=NULL;

	if(*p==NULL)
		*p=newnode;

	else
	{
		while(temp->next!=NULL)
		{
           if(fr<temp->data.freq)
        	   break;
           else
           {
        	   prev=temp;
        	   temp=temp->next;
           }
		}
		if(temp->next==NULL&&fr>temp->data.freq)
			temp->next=newnode;
		else if(temp==*p&&fr<temp->data.freq)
		{
			newnode->next=temp;
			*p=newnode;
		}
		else
		{
			prev->next=newnode;
			newnode->next=temp;
		}
	}
}

node *del(node **p)
{
  node *toBeFreed=*p,*toBeReturned=*p;
  if(*p==NULL)
	  return NULL;
  toBeFreed->next=NULL;
  *p=toBeFreed;
  free(toBeFreed);
  return toBeReturned;
}

void strrev(char *a)
{
	int i,j,l;
	char temp;
	l=strlen(a);
	for(i=0,j=l-1;i<j;i++,j--)
	{
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
}

int main(void) {
	int n,i,fr,j;
	node *p;char b[255][10];
	char arr[10];
	//puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	printf("Enter how many\n");
	scanf("%d",&n);
	char *a=(char *)malloc(n*sizeof(char));
	for(i=0;i<n;i++)
	{
		printf("Enter letter:\n");
		scanf("%s",a);
		printf("enter frequency:\n");
		scanf("%d",&fr);
		insert(&p,a,fr);
	}
	while(p->next!=NULL)
	{
		node *first=del(&p);
			node *sec=del(&p);
			for(i=0;first->data.a[i];i++)
			{
				strcat(b[first->data.a[i]],"0");
			}
			for(i=0;sec->data.a[i];i++)
						{
							strcat(b[sec->data.a[i]],"0");
						}

			fr=first->data.freq+sec->data.freq;
			strcpy(arr,first->data.a);
			strcat(arr,sec->data.a);
			insert(&p,arr,fr);
	}

	for(i=0;i<n;i++)
	{
		strrev(b[i]);
	}
	for(i=0;i<n;i++)
		{
		  for(j=0;j<10;j++)
		  {
			  if(b[i][j]==1||b[i][j]==0)
			printf("%c",(b[i][j]));
		  }
		}
	return EXIT_SUCCESS;
}
