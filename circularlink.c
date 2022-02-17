// create circular link list
//display cicrularll
//insert node at beginning

#include<stdlib.h>
#include<stdio.h>

struct node {
int data;
struct node* next;
};
struct node* head;
struct node* temp;

// create circular link list

void createcll()
{
int choice=1;
struct node* newnode;
head=NULL;
while(choice)
{
newnode= (struct node*)malloc(sizeof(struct node));
printf("Enter the data \n");
scanf("%d",&newnode->data);
newnode->next=NULL;
if(head==NULL)
{
head=temp=newnode;
}
else
{
temp->next=newnode;
temp=newnode;
}
temp->next=head;
printf("1 for continue 0 for exit" );
scanf("%d\n",&choice);
}
}

//display cicrularll 
void display()
{
if(head==NULL)
{
printf("list is empty\n");
}
else
{
temp=head;
while(temp->next!=head)
{
printf("%d " ,temp->data);
temp=temp->next;
}
printf("%d " ,temp->data);
}
}

//insert node at beginning

void insertbegin()
{
struct node* newnode;
newnode=(struct node*)malloc(sizeof(struct node));
printf("enter the data: ");
scanf("%d",&newnode->data);
newnode->next=0;
if(head==NULL)
{
head=newnode;
}
else
{
newnode->next=head->next;
}
head->next=newnode;
}

int main()
{
createcll();
printf("The list is : ");
display();
insertbegin();
display();

}


