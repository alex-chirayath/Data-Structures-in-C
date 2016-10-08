/*
  Program:Implementation of circular queue*/

#include<stdio.h>
#include<stdlib.h>
#define SIZE 20

typedef struct
{
 int a[SIZE];
 int rear,front;
}Queue;
 
void enqueue(Queue * ,int ele);
int dequeue(Queue * );
void display(Queue );

int main()
{
 Queue q;
 int ele,ch;
 q.rear=q.front=0;
 while(1)
 {
  printf("Enter \n1.Enqueue \n2.Dequeue \n3.Display \n4.Exit \n");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
     printf("Enter element to be inserted:");
     scanf("%d",&ele);
     enqueue(&q,ele);
     break;
   case 2:
     ele=dequeue(&q);
     printf("Element deleted is:%d \n",ele);
     break;
   case 3:
     printf("The elements of the queue are:\n");
     display(q);
     break;
   case 4:
     exit(1);
   }
 }
 return 0;
}

void enqueue(Queue *pq,int ele)
{
 if((pq->rear+1)%SIZE==pq->front)
   printf("Queue is full");
 else
  {
   pq->rear=(pq->rear+1)%SIZE;
   pq->a[pq->rear]=ele;
  }
}

int dequeue(Queue *pq)
{
 if(pq->front==pq->rear)
   printf("Queue is empty");
 else
  {
   pq->front=(pq->front+1)%SIZE;
   return(pq->a[pq->front]);
  }
}

void display(Queue q)
{
 int i;
 for(i=(q.front+1)%SIZE;i<=q.rear;i++)
 {
  printf("%d ",q.a[i]);
 }
 printf("\n");
}

/*Output:
Enter 
1.Enqueue 
2.Dequeue 
3.Display 
4.Exit 
1
Enter element to be inserted:11
Enter 
1.Enqueue 
2.Dequeue 
3.Display 
4.Exit 
1
Enter element to be inserted:22
Enter 
1.Enqueue 
2.Dequeue 
3.Display 
4.Exit 
1
Enter element to be inserted:33
Enter 
1.Enqueue 
2.Dequeue 
3.Display 
4.Exit 
1
Enter element to be inserted:44
Enter 
1.Enqueue 
2.Dequeue 
3.Display 
4.Exit 
2
Element deleted is:11 
Enter 
1.Enqueue 
2.Dequeue 
3.Display 
4.Exit 
3
The elements of the queue are:
22 33 44 
Enter 
1.Enqueue 
2.Dequeue 
3.Display 
4.Exit 
4 */






















