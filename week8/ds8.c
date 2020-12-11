#include <stdio.h>
#include <stdlib.h>
void push();
void pop();
void display_s();
void insert();
void delete();
void display_q();
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;
int main()
{
	int choice,ch;
	printf("---STACK---\n");	
    do
    {
    printf("1. Push \n2. Pop  \n3. Display \n");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: push();break;
        case 2: pop();break;
        case 3: display_s();break;
        default: printf("Wrong choice");		
    }
	printf("\nPress 1 if you want to continue else any other number\n");
    scanf("%d",&ch);
    }while(ch==1);
    
    printf("---QUEUE---\n");
    head=NULL;	
    do
    {
    printf("1. Insert \n2. Delete \n3. Display \n");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: insert();break;
        case 2: delete();break;
        case 3: display_q();break;
        default: printf("Wrong choice");		
    }
	printf("\nPress 1 if you want to continue else any other number\n");
    scanf("%d",&ch);
    }while(ch==1);
    
    return 0;
}
void push()
{
	int item;
	struct node *newnode,*temp;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter the item to be pushed\n");
	scanf("%d",&item);
	newnode->data=item;
	if(head==NULL)
	{
		newnode->next=NULL;
		head=newnode;
		return;
	}
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newnode;
	newnode->next=NULL;
}
void pop()
{
	if(head==NULL)
	{
		printf("Stack is empty\n");
		return;
	}
	if(head->next==NULL)
	{
		printf("Poped element is %d\n",head->data);
		head=NULL;
		return;
	}
	struct node *temp;
	temp=head;
	while(temp->next->next!=NULL)
	{
		temp=temp->next;
	}
	printf("Poped element is %d\n",temp->next->data);
	temp->next=NULL;
}
void display_s()
{
    struct node *ptr=NULL;
    ptr=head;
     
    if(ptr==NULL)
    {
        printf("Nothing to print\n");
    }
    else
    {
        while(ptr!=NULL)
       {
        printf("%d ",ptr->data);
        ptr=ptr->next;
       }
    }
    
}
void insert()
{
	int item;
	struct node *newnode,*temp;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter the item to be inserted\n");
	scanf("%d",&item);
	newnode->data=item;
	if(head==NULL)
	{
		newnode->next=NULL;
		head=newnode;
		return;
	}
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newnode;
	newnode->next=NULL;
}
void delete()
{
	if(head==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
		printf("Deleted element is %d\n",head->data);
		head=head->next;
}
void display_q()
{
    struct node *ptr=NULL;
    ptr=head;
     
    if(ptr==NULL)
    {
        printf("Nothing to print\n");
    }
    else
    {
        while(ptr!=NULL)
       {
        printf("%d ",ptr->data);
        ptr=ptr->next;
       }
    }
    
}


