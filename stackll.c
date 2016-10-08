/*  Program :Stack using linked list*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
 int data;
 struct node *next;
}Node;

typedef struct
{
 Node *top;
}StackLL;

void push(StackLL * ,int );
int pop(StackLL * );
void display(StackLL );

int main()
{
 int ch,ele;
 StackLL s;
 s.top=NULL;
 while(1)
 {
  printf("\nEnter \n1.To push a element \n2.To pop a element \n3.To display \n4.Exit \n");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
       printf("Enter element to be pushed:");
       scanf("%d",&ele);
       push(&q,ele);
       break;
   case 2:
       ele=pop(&q);
       printf("The element to popped:%d \n",ele);
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

Node * create()
{
   Node *y;
   y=(Node *)malloc(sizeof(Node));
    y->next=NULL;
    return y;
}
void push(StackLL *s ,int ele)
{

  Node *p=create();
 p->data=ele;

 if(s->top==NULL)
 {
  s->top=p;
 }
 else
 {
  p->next=s->top;
  s->top=p;
 }
}
void destroy(Node *p)
{
    free(p);
}
int pop(StackLL *s)
{
 Node *p;
 int ele;
 if(s->top==NULL)
 {
  printf("Stack underflow");
 }
 else
 {
  p=s->top;
  ele=p->data;
  s->top=s->top->next;
  destroy(p);
  return ele;
 }
}

void display(StackLL s)
{
 Node *q;
 if(s.top==NULL)
 {
  printf("Stack underflow");
 }
 else
 {
  q=s.top;
  while(q!=NULL)
  {
   printf("%d ",q->data);
   q=q->next;
  }
 }
}

/*Output:
Enter
1.To push a element
2.To pop a element
3.To display
4.Exit
1
Enter element to be pushed:11

Enter
1.To push a element
2.To pop a element
3.To display
4.Exit
1
Enter element to be pushed:22

Enter
1.To push a element
2.To pop a element
3.To display
4.Exit
1
Enter element to be pushed:33

Enter
1.To push a element
2.To pop a element
3.To display
4.Exit
1
Enter element to be pushed:44

Enter
1.To push a element
2.To pop a element
3.To display
4.Exit
2
The element to popped:44

Enter
1.To push a element
2.To pop a element
3.To display
4.Exit
3

The contents are:
33 22 11

Enter
1.To push a element
2.To pop a element
3.To display
4.Exit
4
*/
