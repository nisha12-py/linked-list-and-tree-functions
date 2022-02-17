//insertion at nth position
//display linked list
//count of linked list
//delete at beginning position
//Delete from end position
//delete from nth position


#include<stdlib.h>
#include<stdio.h>

struct node {
int data;
struct node* next;
};
struct node* head;
struct node* temp;

//insertion at nth position

void insert(int data, int n)
{
struct node* temp1= (struct node*)malloc(sizeof(struct node));
temp1->data=data;
temp1->next=NULL;
if(n==1) {
temp1->next=head;
head=temp1;
return;
}
struct node* temp2=(struct node*)malloc(sizeof(struct node));
temp2=head;
for(int i=0;i<n-2;i++) {
temp2=temp2->next;
}
temp1->next=temp2->next;
temp2->next=temp1;
}

//display linked list
void display()
{
struct node* temp=head;
printf("list is:  ");
while(temp != NULL)
{
printf("%d",temp->data);
temp=temp->next;
}
printf("\n");
}

//count of linked list

void getlength()
{
int count=0;
temp=head;
while(temp!=NULL)
{
count++;
temp=temp->next;
}
printf("Lenght is %d\n", count);
}

//delete at beginning position

void deleteBegin()
{
//struct node* temp;
temp=head;
head=head->next;
free(temp);
printf("After deleting beginning node\n");
}

//Delete from end position

 void deletefromEnd()
{
struct node* prevnode;
temp=head;
while(temp->next!=NULL)
{
prevnode=temp;
temp=temp->next;
}
prevnode->next=NULL;
free(temp);
printf("After deleting end node\n");
}

//delete from nth position
void deleteNthposition()
{
struct node* nextnode;
int pos,i=1;
temp=head;
printf("ENter the position which you want to delete\n");
scanf("%d",&pos);
while(i<pos-1)
{
temp=temp->next;
i++;
}
nextnode=temp->next;
temp->next=nextnode->next;
free(nextnode);
printf("After deleting the node:\n");
}

int main() {
head=NULL; //empty list;
insert(2,1);
insert(3,2);
insert(4,1);
insert(5,2);
insert(8,3);
insert(7,4);
insert(6,5);
display();
getlength();
deleteBegin();
display();
deletefromEnd();
display();
deleteNthposition();
display();
}

