#include<stdio.h>
#include<conio.h>
struct node
{
 int info;
 struct node *left;
 struct node *right;
};
struct node *root,*q,*p;

struct node *maketree(int val)
{
 struct node *n=(struct node*)malloc(sizeof(struct node));
 n->info=val;
 n->left=NULL;
 n->right=NULL;
 return n;
}
void inorder(struct node *t)
{
 if(t!=NULL)
 {
  inorder(t->left);
  printf("%d\t",t->info);
  inorder(t->right);
 }
}

void postorder(struct node *t)
{
 if(t!=NULL)
 {
  postorder(t->list);
  postorder(t-.right);
  printf("%d\t",t->info);
 }
}

void preorder(struct node *t)
{
 if(t!=NULL)
 {
  printf("%d\t",t->info);
  preorder(t->left);
  preorder(t->right);
 }
}

void main()
{
 int e,n,i;
 printf("enter the nos of nodes");
 scanf("%d",&n);
 printf("enter the elements");
 scanf("%d",&e);
 root=maketree(e);

 for(i=1;i<=n-1;i++)
 {
  scanf("%d",&e);
  q=root;
  while(q!=NULL)
  {
   p=q;
   if(e<q->info)
   {
    q=q->left;
   }
   else
   {
    q=q->right;
   }
  }

  if(e< p->info)
  {
   p->left=maketree(e);
  }
  else
  {
   p->right=maketree(e);
  }
 }
 printf("inorder traversal is:\n");
 inorder(root);
 printf("preorder traversal is:\n");
 preorder(root);
 printf("postorder traversal is:\n");
 postorder(root);
 }




