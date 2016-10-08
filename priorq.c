/*  Program :Implement priority queue*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
 int data;
 struct node *next;
}Node;
 
typedef struct
{
 Node *front;
}PQ;

void pqinsert(PQ * ,int );
int pqdelete(PQ * );
void display(PQ );

int main()
{
 int ch,ele;
 PQ q;
 q.front=NULL;
 while(1)
 {
  printf("\nEnter \n1.To insert a element \n2.To delete a element \n3.To display \n4.Exit \n");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
       printf("Enter element to be inserted:");
       scanf("%d",&ele);
       pqinsert(&q,ele);
       break;
   case 2:
       ele=pqdelete(&q);
       if(ele!=-1)
       {
        printf("The element to deleted:%d \n",ele);
       }
       break;
   case 3:
       printf("The contents are:\n");
       display(q);
       break;
   case 4:
       exit(1);
  }
 }
 return 0;
}

void pqinsert(PQ *pr,int ele)
{
 Node *p,*q,*prev;
 p=(Node *)malloc(sizeof(Node));
 p->data=ele;
 p->next=NULL;
 if(pr->front==NULL)
 {
  pr->front=p;
 }
 else
 {
  q=pr->front;
  prev=NULL;
  while(q!=NULL)
  {
   if(ele<q->data)
   {
    if(q==pr->front)
    {
     p->next=pr->front;
     pr->front=p;
    }
    else
    {
     prev->next=p;
     p->next=q;
    }
    break;
   }
   else
   {
    prev=q;
    q=q->next;
   }
  }
  if(q==NULL)
  {
   prev->next=p;
  }
 }
}

int pqdelete(PQ *pr)
{
 Node *q;
 int ele;
 if(pr->front==NULL)
 {
  printf("PQ empty");
  return -1;
 }
 else
 {
  q=pr->front;
  ele=q->data;
  pr->front=q->next;
  free(q);
  return ele;
 }
}

void display(PQ pr)
{
 Node *q;
 q=pr.front;
 if(q==NULL)
 {
  printf("PQ empty");
 }
 else
 {
  while(q!=NULL)
  {
   printf("%d ",q->data);
   q=q->next;
  }
 }
}

/*Output:
Enter 
1.To insert a element 
2.To delete a element 
3.To display 
4.Exit 
1
Enter element to be inserted:45

Enter 
1.To insert a element 
2.To delete a element 
3.To display 
4.Exit 
1
Enter element to be inserted:23

Enter 
1.To insert a element 
2.To delete a element 
3.To display 
4.Exit 
1
Enter element to be inserted:76

Enter 
1.To insert a element 
2.To delete a element 
3.To display 
4.Exit 
1
Enter element to be inserted:3

Enter 
1.To insert a element 
2.To delete a element 
3.To display 
4.Exit 
3
The contents are:
3 23 45 76 

Enter 
1.To insert a element 
2.To delete a element 
3.To display 
4.Exit 
2
The element to deleted:3 

Enter 
1.To insert a element 
2.To delete a element 
3.To display 
4.Exit 
3
The contents are:
23 45 76 

Enter 
1.To insert a element 
2.To delete a element 
3.To display 
4.Exit 
4
*/














 
