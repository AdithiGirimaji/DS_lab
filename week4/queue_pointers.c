#include <stdio.h>
#include <stdlib.h>
#define size 3
void enque(int [], int, int*);
void deque(int [],int*,int*);
void display(int [],int*,int*);
int main()
{
	int queue[size],choice,element,ch, rear=-1,front=0;
    do
    {
    printf("Enter your choice\n");
    printf("1. Insert\n2. Delete\n3. Display\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: printf("Enter the element to be inserted \n");
                scanf("%d",&element);
                enque(queue,element,&rear);
                break;
        case 2: deque(queue,&rear,&front);        
                break;
        case 3: display(queue,&rear,&front);
                break;
        default: printf("Wrong choice\n");
    }
    printf("Do you want to continue?:Press 0 to stop, else press any other number\n");
    scanf("%d",&ch);
    } while(ch!=0);
	return 0;
}

void enque(int queue[], int ele,int *prear)
{
    if (*prear==size-1)
    {
        printf("Queue overflow. This element cannot be added to the queue.\n");
    }
    else
    {
        (*prear)++;
        queue[*prear]=ele;
    }
}

void deque(int queue[], int *prear, int *pfront)
{
    if((*prear)==-1 && ((*pfront)==0))
       printf("Queue is empty\n");
    else
    {
        printf("Deleted element is %d \n",queue[*pfront]);
        (*pfront)++;
        if((*pfront)>(*prear))
        {
			(*pfront)=0;
			(*prear)=-1;
		}
    }
}
     
void display(int queue[],int *prear,int *pfront)
{
	int i;
    printf("The queue elemements are\n");
    for(i=(*pfront);i<=(*prear);i++)
    {
        
        printf("%d\t",queue[i]);
    }
    printf("\n");
}

