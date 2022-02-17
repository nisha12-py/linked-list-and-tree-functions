//insert at beginning;
//display linked list
#include<stdlib.h>
#include<stdio.h>
struct node {
int data;
struct node* next;
};
struct node* head;
//insert at beginning;
void insert(int x)
{
struct node* temp= (struct node*)malloc(sizeof(struct node));
temp->data =x;
temp->next=head;
head=temp;
}
//display
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
int main() {
head=NULL; //empty list;
printf("how many numbers?\n");
int n,i,x;
scanf("%d",&n);
for(i=0;i<=n;i++){
printf("enter the number \n");
scanf("%d",&x);
insert(x);
display();
}
}
