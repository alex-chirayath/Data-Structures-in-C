/* Program :Stack Implementation*/

#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

struct stack
{
 double a[SIZE];
 int top;
};

void push( struct stack * ,double );
double pop(struct stack * );
void display(struct stack );

int main()
{
 int ch;
 double x;
 struct stack s;
 s.top=-1;
 while(1)
 {
  printf("\nEnter \n1 to push element\n2 to pop element \n3 to display elememts and \n4 to exit\n");
  scanf("%d",&ch);
  switch(ch)
  {
  case 1:
    printf("Enter element to be pushed:");
    scanf("%lf",&x);
    push(&s,x);
    break;

  case 2:
   x=pop(&s);
   printf("The elememt popped out is: %lf",x);
   break;

  case 3:
   display(s);
   break;

  case 4:
   exit(0);
  }
 }
 return 0;
}

void push(struct stack *ps,double k)
{
 if(ps->top==SIZE-1)
 {
  printf("Stack overflow");
 }
 else
 {
  ps->top++;
  ps->a[ps->top]=k;
 }
}


double pop(struct stack *ps)
{
 if(ps->top==-1)
  printf("Stack is empty");
 else
  return(ps->a[ps->top--]);
}

void display(struct stack ps)
{
 int i;
 printf("The contents of stack are: \n");
 for(i=ps.top;i>=0;i--)
 {
  printf("%lf",ps.a[i]);
 }
}


/*Output:

Enter
1 to push element
2 to pop element
3 to display elememts and
4 to exit
1
Enter element to be pushed:23

Enter
1 to push element
2 to pop element
3 to display elememts and
4 to exit
1
Enter element to be pushed:45

Enter
1 to push element
2 to pop element
3 to display elememts and
4 to exit
1
Enter element to be pushed:34

Enter
1 to push element
2 to pop element
3 to display elememts and
4 to exit
2
The elememt popped out is: 34.000000

Enter
1 to push element
2 to pop element
3 to display elememts and
4 to exit
3
The contents of stack are:
45.00000023.000000

Enter
1 to push element
2 to pop element
3 to display elememts and
4 to exit
4
*/







