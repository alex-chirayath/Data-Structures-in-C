// Implementation of BInary Tree in C
#include<stdio.h>
#include<stdlib.h>

int ncount=0;
int lfcount=0;

typedef struct TNODE
{
 int data;
 struct TNODE *left,*right;
}tnode;
typedef struct
{
 tnode *root;
}tree;

void insert(tree *,int );
void delete(tree *,int );
void nodecount(tnode * );
void leafcount(tnode * );
int depth(tnode * );
void preorder(tnode * );
void inorder(tnode * );
void postorder(tnode * );

int main()
{
 tree t;
 t.root=NULL;
 int ch,ele,count,dep;
 while(1)
 {
  printf("\nEnter \n1.To insert a node \n2.To delete a node \n3.To count total no. nodes \n4.To count total no.of leaf nodes \n5.To find depth of tree \n6.For preorder traversal \n7.For inorder traversal \n8.For postorder traversal \n9.Exit \n");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
       printf("Enter element to be inserted:");
       scanf("%d",&ele);
       insert(&t,ele);
       break;
   case 2:
       printf("Enter the element to be deleted:");
       scanf("%d",&ele);
       delete(&t,ele);
       printf("The element deleted:%d \n",ele);
       break;
   case 3:
       nodecount(t.root);
       printf("The total no. of nodes are:\n");
       printf("%d",ncount);
       break;
   case 4:
       leafcount(t.root);
       printf("The total no. of  leaf nodes are:\n");
       printf("%d",lfcount);
       break;
   case 5:
       dep=depth(t.root);
       printf("The depth is:%d",dep);
       break;
   case 6:
       printf("The preorder format is \n");
       preorder(t.root);
       break;
   case 7:
       printf("The inorder format is \n");
       inorder(t.root);
       break;
   case 8:
       printf("The postorder format is \n");
       postorder(t.root);
       break;
   case 9:
       exit(1);
  }
 }
 return 0;
}

void insert(tree *tptr,int x)
{
 tnode *p,*temp,*q;
 p=(tnode* )malloc(sizeof(tnode));
 p->data=x;
 p->left=p->right=NULL;
 if(tptr->root==NULL)
   tptr->root=p;
 else
 {
   temp=tptr->root;
   while(temp!=NULL)
   {
    q=temp;
    if(x<temp->data)
      temp=temp->left;
    else
      temp=temp->right;
   }
   if(p->data<q->data)
      q->left=p;
   else
      q->right=p;
 }
}

void delete(tree *tptr,int x)
{
 tnode *p=tptr->root;
 tnode *f,*s,*rp,*prev=NULL;
 while(p!=NULL)
 {
  if(p->data==x)
    break;
  else
  {
   prev=p;
   if(x<p->data)
     p=p->left;
   else
     p=p->right;
  }
 }
 if(p==NULL)
 {
  printf("No data found");
  exit(0);
 }
 if((p->left==NULL)&&(p->right==NULL))
    rp=NULL;
 else if(p->left==NULL)
    rp=p->right;
 else if(p->right==NULL)
    rp=p->left;
 else
 {
  rp=p->right;
  s=rp->left;
  while(s!=NULL)
  {
   f=rp;
   rp=s;
   s=rp->left;
  }
  f->left=rp->right;
  rp->left=p->left;
  rp->right=p->right;
 }
 if(prev==NULL)
   tptr->root=rp;
 else
 {
   if(prev->left==p)
     prev->left=rp;
   else
     prev->right=rp;
 }
 free(p);
}

void nodecount(tnode *tptr)
{
 if(tptr!=NULL)
 {
  ncount++;
  nodecount(tptr->left);
  nodecount(tptr->right);
 }
}

void leafcount(tnode *tptr)
{
 if(tptr!=NULL)
 {
  if((tptr->left==NULL)&&(tptr->right==NULL))
    lfcount++;
  else
  {
    leafcount(tptr->left);
    leafcount(tptr->right);
  }
 }
}

int depth(tnode *p)
{
 int ld=0,rd=0;
 if(p==NULL)
   return -1;
 else if((p->left==NULL)&&(p->right==NULL))
   return 0;
 else
 {
  ld=depth(p->left);
  rd=depth(p->right);
  if(ld>rd)
    return ld+1;
  else
    return rd+1;
 }
}

void preorder(tnode *p)
{

 if(p!=NULL)
 {
  printf("%d ",p->data);
  preorder(p->left);
  preorder(p->right);
 }
}

void inorder(tnode *p)
{

 if(p!=NULL)
 {
  inorder(p->left);
  printf("%d ",p->data);
  inorder(p->right);
 }
}

void postorder(tnode *p)
{
 if(p!=NULL)
 {
  postorder(p->left);
  postorder(p->right);
  printf("%d ",p->data);
 }
}
/*Output:
Enter
1.To insert a node
2.To delete a node
3.To count total no. nodes
4.To count total no.of leaf nodes
5.To find depth of tree
6.For preorder traversal
7.For inorder traversal
8.For postorder traversal
9.Exit
1
Enter element to be inserted:11

Enter
1.To insert a node
2.To delete a node
3.To count total no. nodes
4.To count total no.of leaf nodes
5.To find depth of tree
6.For preorder traversal
7.For inorder traversal
8.For postorder traversal
9.Exit
1
Enter element to be inserted:22

Enter
1.To insert a node
2.To delete a node
3.To count total no. nodes
4.To count total no.of leaf nodes
5.To find depth of tree
6.For preorder traversal
7.For inorder traversal
8.For postorder traversal
9.Exit
1
Enter element to be inserted:33

Enter
1.To insert a node
2.To delete a node
3.To count total no. nodes
4.To count total no.of leaf nodes
5.To find depth of tree
6.For preorder traversal
7.For inorder traversal
8.For postorder traversal
9.Exit
1
Enter element to be inserted:44

Enter
1.To insert a node
2.To delete a node
3.To count total no. nodes
4.To count total no.of leaf nodes
5.To find depth of tree
6.For preorder traversal
7.For inorder traversal
8.For postorder traversal
9.Exit
1
Enter element to be inserted:55

Enter
1.To insert a node
2.To delete a node
3.To count total no. nodes
4.To count total no.of leaf nodes
5.To find depth of tree
6.For preorder traversal
7.For inorder traversal
8.For postorder traversal
9.Exit
2
Enter the element to be deleted:22
The element deleted:22

Enter
1.To insert a node
2.To delete a node
3.To count total no. nodes
4.To count total no.of leaf nodes
5.To find depth of tree
6.For preorder traversal
7.For inorder traversal
8.For postorder traversal
9.Exit
3
The total no. of nodes are:
4

Enter
1.To insert a node
2.To delete a node
3.To count total no. nodes
4.To count total no.of leaf nodes
5.To find depth of tree
6.For preorder traversal
7.For inorder traversal
8.For postorder traversal
9.Exit
4
The total no. of  leaf nodes are:
1

Enter
1.To insert a node
2.To delete a node
3.To count total no. nodes
4.To count total no.of leaf nodes
5.To find depth of tree
6.For preorder traversal
7.For inorder traversal
8.For postorder traversal
9.Exit
5
The depth is:3

Enter
1.To insert a node
2.To delete a node
3.To count total no. nodes
4.To count total no.of leaf nodes
5.To find depth of tree
6.For preorder traversal
7.For inorder traversal
8.For postorder traversal
9.Exit
6
The preorder format is
11 33 44 55

Enter
1.To insert a node
2.To delete a node
3.To count total no. nodes
4.To count total no.of leaf nodes
5.To find depth of tree
6.For preorder traversal
7.For inorder traversal
8.For postorder traversal
9.Exit
7
The inorder format is
11 33 44 55

Enter
1.To insert a node
2.To delete a node
3.To count total no. nodes
4.To count total no.of leaf nodes
5.To find depth of tree
6.For preorder traversal
7.For inorder traversal
8.For postorder traversal
9.Exit
8
The postorder format is
55 44 33 11

Enter
1.To insert a node
2.To delete a node
3.To count total no. nodes
4.To count total no.of leaf nodes
5.To find depth of tree
6.For preorder traversal
7.For inorder traversal
8.For postorder traversal
9.Exit
9*/





