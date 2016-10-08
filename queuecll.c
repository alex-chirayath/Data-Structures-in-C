/*  Program :To implement a queue using Circular Linked List*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
 int data;
 struct node *next;
}Node;
typedef struct 
{
 Node *rear;
}QueueCLL;

void enqueue(QueueCLL * ,int );
int dequeue(QueueCLL * );
void display(QueueCLL );

int main()
{
 int ch,ele;
 QueueCLL q;
 q.rear=NULL;
 while(1)
 {
  printf("\nEnter \n1.To enqueue a element \n2.To dequeue a element \n3.To display \n4.Exit \n");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
       printf("Enter element to be enqueued:");
       scanf("%d",&ele);
       enqueue(&q,ele);
       break;
   case 2:
       ele=dequeue(&q);
       printf("The element to dequeued:%d \n",ele);
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

void enqueue(QueueCLL *q,int ele)
{
 Node *p;
 p=(Node *)malloc(sizeof(Node));
 p->data=ele;
 if(q->rear==NULL)
 {
  q->rear=p;
  p->next=p;
 }
 else
 {
  p->next=q->rear->next;
  q->rear->next=p;
  q->rear=p;
 }
}

int dequeue(QueueCLL *q)
{
 Node *p;
 int ele;
 if(q->rear==NULL)
 {
  printf("Queue empty");
 }
 else
 {
  p=q->rear->next;
  ele=p->data;
  if(p==q->rear)
  {
   q->rear=NULL;
  }
  else
  {
   q->rear->next=p->next;
  }
  free(p);
  return ele;
 }
}

void display(QueueCLL q)
{
 Node *p;
 if(q.rear==NULL)
 {
  printf("Queue empty");
 }
 else
 {
  p=q.rear->next;
  do
  {
   printf("%d ",p->data);
   p=p->next;
  }
  while(p!=q.rear->next);
 }
} 

/*Output:
Enter 
1.To enqueue a element 
2.To dequeue a element 
3.To display 
4.Exit 
1
Enter element to be enqueued:11

Enter 
1.To enqueue a element 
2.To dequeue a element 
3.To display 
4.Exit 
1
Enter element to be enqueued:22

Enter 
1.To enqueue a element 
2.To dequeue a element 
3.To display 
4.Exit 
1
Enter element to be enqueued:33

Enter 
1.To enqueue a element 
2.To dequeue a element 
3.To display 
4.Exit 
1
Enter element to be enqueued:44

Enter 
1.To enqueue a element 
2.To dequeue a element 
3.To display 
4.Exit 
2
The element to dequeued:11 

Enter 
1.To enqueue a element 
2.To dequeue a element 
3.To display 
4.Exit 
3
The contents are:
22 33 44 

Enter 
1.To enqueue a element 
2.To dequeue a element 
3.To display 
4.Exit 
4*/
