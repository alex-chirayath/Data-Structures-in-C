/* Program :Queue using linked list*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
 int data;
 struct node *next;
}Node;

typedef struct
{
 Node *rear,*front;
}QueueLL;

void enqueue(QueueLL * ,int );
int dequeue(QueueLL * );
void display(QueueLL );

int main()
{
 int ch,ele;
 QueueLL q;
 q.front=q.rear=NULL;
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

Node *create()
{
 Node *y;
 y=(Node *)malloc(sizeof(Node));
 y->next=NULL;
 return y;
}
void enqueue(QueueLL *q,int ele)
{
 Node *p;
 p=create();
 p->data=ele;

 if(q->rear==NULL)
 {
  q->rear=q->front=p;
 }
 else
 {
  q->rear->next=p;
  q->rear=p;
 }
}
void destroy(Node *p)
{
    free(p);
}
int dequeue(QueueLL *q)
{
 Node *p;
 int ele;
 if(q->front==NULL)
 {
  printf("Queue empty");
 }
 else
 {
  p=q->front;
  ele=p->data;
  q->front=q->front->next;
  if(q->front==NULL)
  {
   q->rear=NULL;
  }
  destroy(p);
  return ele;
 }
}

void display(QueueLL q)
{
 Node *p;
 if(q.front==NULL)
 {
  printf("Queue empty");
 }
 else
 {
  p=q.front;
  while(p!=NULL)
  {
   printf("%d ",p->data);
   p=p->next;
  }
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
4
*/
