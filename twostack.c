/*Program :Implementing two stacks in a single array*/

#include<stdio.h>
#include<stdlib.h>

void push1(int a[],int* ,int ,int );
void push2(int a[],int ,int* ,int );
void display(int a[],int );

int main()
{
 int a[100],top1,top2,n,x,ch;
 printf("Enter the size of the array \n");
 scanf("%d",&n);
 top1=-1;
 top2=n;
 while(top1!=(top2-1))
 {
   printf("Enter 1 to push a element in stack1 and 2 to push element in stack2 \n");
   scanf("%d",&ch);
   printf("Enter the element to be pushed \n");
   scanf("%d",&x);
   switch(ch)
   {
       case 1:
          push1(a,&top1,top2,x);
          break;
       case 2:
          push2(a,top1,&top2,x);
          break;
   }
   
 }
 printf("Stack is full \n");
 display(a,n);
 return 0;
}

void push1(int a[],int *top1,int top2,int x)
{
 (*top1)++;  
 a[*top1]=x;
}


void push2(int a[],int top1,int *top2,int x)
{
 (*top2)--;  
 a[*top2]=x;
}


void display(int a[],int n)
{
 int i;
 printf("The contents of stack are \n");
 for(i=0;i<n;i++)
 {
  printf("%d ",a[i]);
 }
}

/*Output:
Enter the size of the array 
4
Enter 1 to push a element in stack1 and 2 to push element in stack2 
1
Enter the element to be pushed 
11
Enter 1 to push a element in stack1 and 2 to push element in stack2 
2
Enter the element to be pushed 
22
Enter 1 to push a element in stack1 and 2 to push element in stack2 
1
Enter the element to be pushed 
33
Enter 1 to push a element in stack1 and 2 to push element in stack2 
2
Enter the element to be pushed 
44
Stack is full 
The contents of stack are 
11 33 44 22 
*/



