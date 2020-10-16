#include <stdio.h>
#define size 3
int top=-1;
void push(int [], int);
int pop(int[]);
void display(int []);
int main()
{
	int stack[size],choice,element,ch;
    do
    {
    printf("Enter your choice\n");
    printf("1. Push\n2. Pop\n3. Display\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: printf("Enter the element to be pushed \n");
                scanf("%d",&element);
                push(stack,element);
                break;
        case 2: element=pop(stack);
                if(element==-1)
                    printf("Stack Underflow\n");
                else
                   printf("Poped element is %d \n",element);
                break;
        case 3: display(stack);
                break;
        default: printf("Wrong choice\n");
    }
    printf("Do you want to continue?:Press 0 to stop, else press any other number\n");
    scanf("%d",&ch);
    } while(ch!=0);
	return 0;
}

void push(int stack[], int ele)
{
    if (top==size-1)
    {
        printf("Stack overflow. This element cannot be added to stack.\n");
    }
    else
    {
        top++;
        stack[top]=ele;
    }
}

int pop(int stack[])
{
    int popele;
    if(top==-1)
    
       return -1;
      
    else
    {
        popele=stack[top];
        top--;
        return popele;
    }
     
     
}

void display(int stack[])
{
	int i;
    printf("The stack elemements are\n");
    for(i=top;i>=0;i--)
    {
        
        printf("%d\t",stack[i]);
    }
    printf("\n");
}
