// tree traversal in C
// preorder traversal
// inorder traversal
// postorder traversal
// Create a new Node

#include <stdio.h>
#include <stdlib.h>

struct node {
int data;
struct node* l;
struct node* r;
};

// preorder traversal
void preorder(struct node* t)
{
if (t == NULL) return;
printf("%d ->", t->data);
preorder(t->l);
preorder(t->r);
}

// inorder traversal
void inorder(struct node* t) 
{
if (t == NULL) return;
inorder(t->l);
printf("%d ->", t->data);
inorder(t->r);
}

// postorder traversal
void postorder(struct node* t)
{
if (t == NULL) return;
postorder(t->l);
postorder(t->r);
printf("%d ->", t->data);
}

// Create a new Node
struct node* create(value) 
{
struct node* newNode = malloc(sizeof(struct node));
newNode->data = value;
newNode->l = NULL;
newNode->r = NULL;
return newNode;
}

// Insert on the left of the node
struct node* insertLeft(struct node* t, int value)
{
t->l = create(value);
return t->l;
}

// Insert on the right of the node
struct node* insertRight(struct node* t, int value) 
{
t->r = create(value);
return t->r;
}

int main()
{
struct node* t = create(1);
insertLeft(t, 2);
insertRight(t, 3);
insertLeft(t->l, 4);
insertLeft(t->r, 5);
printf("Inorder traversal \n");
inorder(t);
printf("\nPreorder traversal \n");
preorder(t);
printf("\nPostorder traversal \n");
postorder(t);
}
