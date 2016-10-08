/*
  Program:Implementation of linked list*/

#include<stdio.h>
#include<stdlib.h>
#define SIZE 20

typedef struct node
{
 int data;
 struct node *next;
}Node;

typedef struct
{
 Node *start;
}LL;

void appendbeg(LL * ,int );
void appendmid(LL * ,int ,int );
void appendend(LL * ,int );
void delete(LL * ,int );
int count(LL );
void display(LL );
void reverse(LL * );
void concate(LL * ,LL );
int maximum(LL );
int minimum(LL );


void split(LL* l1,LL *l2,int n)
{int i;
    Node *q=l1->start;
  for(i=1;i<=n-1;i++)
 {
  q=q->next;
 }
 l2->start=q->next;
 q->next=NULL;

}

int main()
{
 LL l1,l2;
 l1.start=NULL;
 l2.start=NULL;
 int x,y,ele,ch;
 while(1)
 {
  printf("\n Enter \n1.To append node at beginning \n2.To append node after nth node \n3.To append node at end \n4.To delete a node \n5.To count the total no.of nodes \n6.To display the linked list \n7.To reverse a linked list  \n8.To concate two linked lists \n9.To find maximum no. \n10.To find minimum no. \n11.Exit \n");
  scanf("%d",&ch);
  switch(ch)
  {
    case 1:
       printf("Enter the no. to be appended:");
       scanf("%d",&ele);
       appendbeg(&l1,ele);
       break;
    case 2:
       printf("Enter the no. to be appended:");
       scanf("%d",&ele);
       printf("Enter the value of n:");
       scanf("%d",&y);
       appendmid(&l1,ele,y);
       break;
    case 3:
       printf("Enter the no. to be appended:");
       scanf("%d",&ele);
       appendend(&l1,ele);
       break;
    case 4:
       printf("Enter the no. to be deleted:");
       scanf("%d",&ele);
       delete(&l1,ele);
       break;
    case 5:
       x=count(l1);
       printf("The no. of nodes are:%d",x);
       break;
    case 6:
       printf("The contents of linked list are:");
       display(l1);
       break;
    case 7:
       reverse(&l1);
       printf("The contents of reversed linked list are:");
       display(l1);
       break;
    case 8:
       concate(&l1,l2);
       printf("The contents of concated linked list are:");
       display(l1);
       break;
    case 9:
       x=maximum(l1);
       printf("The maximum no. in the linked list is:%d",x);
       break;
    case 10:
       y=minimum(l1);
       printf("The minimum no. in the linked list is:%d",y);
       break;
    case 11:
       exit(1);
  }
 }
 return 0;
}

void appendbeg(LL *l,int ele)
{
 Node *p;
 p=(Node*)malloc(sizeof(Node));
 p->data=ele;
 p->next=l->start;
 l->start=p;
}

void appendmid(LL *l,int ele,int n)
{
 int i;
 Node *p,*q,*r;
 p=(Node*)malloc(sizeof(Node));
 p->data=ele;
 q=l->start;
 for(i=1;i<=n-1;i++)
 {
  q=q->next;
 }
 r=q->next;
 q->next=p;
 p->next=r;
}

void appendend(LL *l,int ele)
{
 Node *p,*q;
 p=(Node*)malloc(sizeof(Node));
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
 }
}

void delete(LL *l,int ele)
{
 Node *p,*q;
 q=l->start;
 while(q!=NULL)
 {
  if(q->data==ele)
  {
   if(q==l->start)
   {
    l->start=l->start->next;
   }
   else
   {
    p->next=q->next;
   }
   free(q);
   break;
  }
  else
  {
   p=q;
   q=q->next;
  }
 }
}

int count(LL l)
{
 int count=0;
 Node *q=l.start;
 while(q!=NULL)
 {
  count++;
  q=q->next;
 }
 return count;
}

void display(LL l)
{
 Node *q=l.start;
 while(q!=NULL)
 {
  printf("%d ",q->data);
  q=q->next;
 }
}

void reverse(LL *l)
{
 Node *p,*q,*r;
 p=NULL;
 q=l->start;
 while(q!=NULL)
 {
  r=q->next;
  q->next=p;
  p=q;
  q=r;
 }
 l->start=p;
}

void concate(LL *l1,LL l2)
{
 int n,ele;
 Node *q;
 q=l1->start;
 printf("Enter the no. of elements in linked list 2:");
 scanf("%d",&n);
 while(n!=0)
 {
  printf("\nEnter the element to be appended:");
  scanf("%d",&ele);
  appendend(&l2,ele);
  n--;
 }
 if(l2.start==NULL)
 {
  return;
 }
 else if(l1->start==NULL)
 {
  l1->start=l2.start;
  return;
 }
 else
 {
  q=l1->start;
  while(q->next!=NULL)
  {
   q=q->next;
  }
  q->next=l2.start;

 }
}

int maximum(LL l)
{
 int max;
 Node *p;
 p=l.start;
 max=p->data;
 while(p!=NULL)
 {
  if(p->data>max)
  {
   max=p->data;
  }
  p=p->next;
 }
 return max;
}

int minimum(LL l)
{
 int min;
 Node *p;
 p=l.start;
 min=p->data;
 while(p!=NULL)
 {
  if(p->data<min)
  {
   min=p->data;
  }
  p=p->next;
 }
 return min;
}

/*Output:
Enter
1.To append node at beginning
2.To append node after nth node
3.To append node at end
4.To delete a node
5.To count the total no.of nodes
6.To display the linked list
7.To reverse a linked list
8.To concate two linked lists
9.To find maximum no.
10.To find minimum no.
11.Exit
1
Enter the no. to be appended:11
Enter
1.To append node at beginning
2.To append node after nth node
3.To append node at end
4.To delete a node
5.To count the total no.of nodes
6.To display the linked list
7.To reverse a linked list
8.To concate two linked lists
9.To find maximum no.
10.To find minimum no.
11.Exit
3
Enter the no. to be appended:33
Enter
1.To append node at beginning
2.To append node after nth node
3.To append node at end
4.To delete a node
5.To count the total no.of nodes
6.To display the linked list
7.To reverse a linked list
8.To concate two linked lists
9.To find maximum no.
10.To find minimum no.
11.Exit
2
Enter the no. to be appended:22
Enter the value of n:2
Enter
1.To append node at beginning
2.To append node after nth node
3.To append node at end
4.To delete a node
5.To count the total no.of nodes
6.To display the linked list
7.To reverse a linked list
8.To concate two linked lists
9.To find maximum no.
10.To find minimum no.
11.Exit
3
Enter the no. to be appended:44
Enter
1.To append node at beginning
2.To append node after nth node
3.To append node at end
4.To delete a node
5.To count the total no.of nodes
6.To display the linked list
7.To reverse a linked list
8.To concate two linked lists
9.To find maximum no.
10.To find minimum no.
11.Exit
4
Enter the no. to be deleted:44
Enter
1.To append node at beginning
2.To append node after nth node
3.To append node at end
4.To delete a node
5.To count the total no.of nodes
6.To display the linked list
7.To reverse a linked list
8.To concate two linked lists
9.To find maximum no.
10.To find minimum no.
11.Exit
5
The no. of nodes are:3
Enter
1.To append node at beginning
2.To append node after nth node
3.To append node at end
4.To delete a node
5.To count the total no.of nodes
6.To display the linked list
7.To reverse a linked list
8.To concate two linked lists
9.To find maximum no.
10.To find minimum no.
11.Exit
6
The contents of linked list are:11 33 22
Enter
1.To append node at beginning
2.To append node after nth node
3.To append node at end
4.To delete a node
5.To count the total no.of nodes
6.To display the linked list
7.To reverse a linked list
8.To concate two linked lists
9.To find maximum no.
10.To find minimum no.
11.Exit
7
The contents of reversed linked list are:22 33 11
Enter
1.To append node at beginning
2.To append node after nth node
3.To append node at end
4.To delete a node
5.To count the total no.of nodes
6.To display the linked list
7.To reverse a linked list
8.To concate two linked lists
9.To find maximum no.
10.To find minimum no.
11.Exit
8
Enter the no. of elements in linked list 2:2

Enter the element to be appended:10

Enter the element to be appended:20
The contents of concated linked list are:22 33 11 10 20
Enter
1.To append node at beginning
2.To append node after nth node
3.To append node at end
4.To delete a node
5.To count the total no.of nodes
6.To display the linked list
7.To reverse a linked list
8.To concate two linked lists
9.To find maximum no.
10.To find minimum no.
11.Exit
9
The maximum no. in the linked list is:33
Enter
1.To append node at beginning
2.To append node after nth node
3.To append node at end
4.To delete a node
5.To count the total no.of nodes
6.To display the linked list
7.To reverse a linked list
8.To concate two linked lists
9.To find maximum no.
10.To find minimum no.
11.Exit
10
The minimum no. in the linked list is:10
Enter
1.To append node at beginning
2.To append node after nth node
3.To append node at end
4.To delete a node
5.To count the total no.of nodes
6.To display the linked list
7.To reverse a linked list
8.To concate two linked lists
9.To find maximum no.
10.To find minimum no.
11.Exit
11
*/





































