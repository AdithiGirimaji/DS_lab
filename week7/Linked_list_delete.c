#include <stdio.h>
#include <stdlib.h>
void create();
void display();
void delete_pos1();
void delete();
void delete_last();
struct node
{
    int id;
    char name[50];
    int sem;
    struct node *next;
};
struct node *head=NULL;
int main(int argc, char **argv)
{
    int choice,ch;
    do
    {
    printf("1. Create \n2. Display  \n3. Delete the first element\n4. Delete an element mentioned\n5.Delete the last element\n");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: create();break;
        case 2: display();break;
        case 3: delete_pos1();break;
        case 4: delete();break;
        case 5: delete_last(); break;
        default: printf("Wrong choice");		
    }
	printf("\nPress 1 if you want to continue else any other number\n");
    scanf("%d",&ch);
    }while(ch==1);
    return 0;
}

void create()
{
   struct node *newnode,*temp;
    int ID,s,j;
    char n[50];
    newnode =(struct node *) malloc (sizeof(struct node));
    printf("Enter the student id,name and sem : ");
    scanf("%d",&ID);
    scanf("%s",n);
    scanf("%d",&s);
    newnode->id=ID;
    for(j=0;;j++)
    {
		newnode->name[j]=n[j];
		if(n[j]=='\0')
		break;
	}
    newnode->sem=s;
    if (head==NULL)
     { 
      newnode->next=NULL;
      head=newnode; 
      printf("Node is created\n");
     }
     else 
    {
    temp=head;
       while(temp->next!=NULL)
       {
          temp=temp->next;
       }
      temp->next=newnode;
      newnode->next=NULL;
      printf("Node is created\n");
   }  
}

void display()
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
        printf("\tID:%d\tName:%s\tSem:%d\n ",ptr->id,ptr->name,ptr->sem);
        ptr=ptr->next;
       }
    }
    
}
void delete_pos1()
{
	if (head == NULL)
     {
         printf("Empty List. Can't delete\n");return;
     }
     else
     {
		 head=head->next;
	 }  
}
	
void delete()
{ 
	int ele;
    printf("Enter the student ID which has to be deleted\n");
    scanf("%d",&ele);
    struct node *temp,*del=NULL;
     
     if (head == NULL)
     {
         printf("Empty List. Can't delete\n");return;
     }
     temp=head;
     if(temp->id==ele)
     {
		head=head->next;
		return;
	 }   
    while (temp->next!=NULL)
    {
        if(temp->next->id==ele)
        {
            del=temp->next;
           if(del->next==NULL)
           temp->next=NULL;
           else
            temp->next=del->next;
        }
            
        else
           temp=temp->next; 
    }
    if(del==NULL)
    {
        printf("Element not found in the list\n");return;
  }
}

void delete_last()
{
	struct node *ptr;
	ptr=head;
	if (head == NULL)
     {
         printf("Empty List. Can't delete\n");return;
     }
     else if(ptr->next==NULL)
     {
		 head=NULL;
	 }
     else
     {
	do
	{
	    if(ptr->next->next==NULL)
	    {
			ptr->next=NULL;
			return;
		}
		ptr=ptr->next;
	}while(1);
     }
}
