/*
  Program :To implement Doubly Linked List*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
 int data;
 struct node *next,*prev;
}DNode;
 
typedef struct
{
 DNode *start;
}DLL;

void insert(DLL * ,int );
int delete(DLL * ,int );
void search(DLL ,int );
void display(DLL );

int main()
{
 int ch,ele;
 DLL l;
 l.start=NULL;
 while(1)
 {
  printf("\nEnter \n1.To insert a element \n2.To delete a element \n3.To search an element \n4.To display \n5.Exit \n");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
       printf("Enter element to be inserted:");
       scanf("%d",&ele);
       insert(&l,ele);
       break;
   case 2:
       printf("Enter element to be deleted:");
       scanf("%d",&ele);
       delete(&l,ele);
       break;
   case 3:
       printf("Enter element to be searched:");
       scanf("%d",&ele);
       search(l,ele);
       break;
   case 4:
       printf("The contents are:\n");
       display(l);
       break;
   case 5:
       exit(1);
  }
 }
 return 0;
}

void insert(DLL *l,int ele)
{
 DNode *p,*q;
 p=(DNode *)malloc(sizeof(DNode));
 p->data=ele;
 p->next=NULL;
 if(l->start==NULL)
 {
  l->start=p;
 }
 else
 {
  q=l->start;
  while(q->next!=NULL)
  {
   q=q->next;
  }
  q->next=p;
  p->prev=q;
 }
}

int delete(DLL *l,int ele)
{
 DNode *p,*q,*r;
 p=l->start;
 while(p!=NULL)
 {
  if(p->data==ele)
  {
   if(p==l->start)
   {
    l->start=p->next;
    l->start->prev=NULL;
   }
   else
   {
    q=p->prev;
    r=p->next;
    if(r!=NULL)
    {
     r->prev=q;
    }
   q->next=r;
   }
   free(p);
   break;
  }
  else
  {
   p=p->next;
  }
 }
}

void search(DLL l,int ele)
{
 DNode *p;
 if(l.start==NULL)
 {
  printf("Queue empty");
 }
 else
 {
  p=l.start;
  while(p!=NULL)
  {
   if(p->data==ele)
   {
     printf("Element is found");
     return;
   }
   else
   {
    p=p->next;
   }
  } 
 printf("Element is not found");
 } 
}

void display(DLL l)
{
 DNode *p;
 if(l.start==NULL)
 {
  printf("Queue empty");
 }
 else
 {
  p=l.start;
  while(p!=NULL)
  {
   printf("%d ",p->data);
   p=p->next;
  }
 }
} 

/*Output:
Enter 
1.To insert a element 
2.To delete a element 
3.To search an element 
4.To display 
5.Exit 
1
Enter element to be inserted:11

Enter 
1.To insert a element 
2.To delete a element 
3.To search an element 
4.To display 
5.Exit 
1
Enter element to be inserted:22

Enter 
1.To insert a element 
2.To delete a element 
3.To search an element 
4.To display 
5.Exit 
1
Enter element to be inserted:33

Enter 
1.To insert a element 
2.To delete a element 
3.To search an element 
4.To display 
5.Exit 
1
Enter element to be inserted:44

Enter 
1.To insert a element 
2.To delete a element 
3.To search an element 
4.To display 
5.Exit 
2
Enter element to be deleted:22

Enter 
1.To insert a element 
2.To delete a element 
3.To search an element 
4.To display 
5.Exit 
3
Enter element to be searched:11
Element is found

Enter 
1.To insert a element 
2.To delete a element 
3.To search an element 
4.To display 
5.Exit 
4
The contents are:
11 33 44 

Enter 
1.To insert a element 
2.To delete a element 
3.To search an element 
4.To display 
5.Exit 
5*/


