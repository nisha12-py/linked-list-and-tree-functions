// insert node at the front
// insert a node after a specific node
// insert a newNode at the end of the list
// delete a node from the doubly linked list
// display the doubly linked list
// delete the last node
#include <stdio.h>
#include <stdlib.h>
struct Node
{
int data;
struct Node* next;
struct Node* prev;
};

// insert node at the front
void insertFront(struct Node** head, int data)
{
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = (*head);
newNode->prev = NULL;
if ((*head) != NULL)
(*head)->prev = newNode;
(*head) = newNode;
}

// insert a node after a specific node
void insertAfter(struct Node* prev_node, int data)
{
if (prev_node == NULL) {
printf("previous node cannot be null");
return;
}
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = prev_node->next;
prev_node->next = newNode;
newNode->prev = prev_node;
if (newNode->next != NULL)
newNode->next->prev = newNode;
}

// insert a newNode at the end of the list
void insertEnd(struct Node** head, int data)
{
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = NULL;
struct Node* temp = *head;
if (*head == NULL) {
newNode->prev = NULL;
*head = newNode;
return;
}
while (temp->next != NULL)
temp = temp->next;
temp->next = newNode;
newNode->prev = temp;
}

// delete a node from the doubly linked list
void deleteNode(struct Node** head, struct Node* del_node)
{
if (*head == NULL || del_node == NULL)
return;
if (*head == del_node)
*head = del_node->next;
if (del_node->next != NULL)
del_node->next->prev = del_node->prev;
if (del_node->prev != NULL)
del_node->prev->next = del_node->next;
free(del_node);
}

// disply the doubly linked list
void displayList(struct Node* node)
{
struct Node* last;
while (node != NULL) {
printf("%d->", node->data);
last = node;
node = node->next;
}
if (node == NULL)
printf("NULL\n");
}

int main() 
{
struct Node* head = NULL;
insertEnd(&head, 9);
insertFront(&head, 6);
insertFront(&head, 8);
insertEnd(&head, 88);
insertAfter(head, 55);
insertAfter(head->next, 15);
displayList(head);
// delete the last node
deleteNode(&head, head->next->next->next->next->next);
displayList(head);
}
