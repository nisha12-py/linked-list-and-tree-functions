// Binary Search Tree operations in C
// Create a node
// Inorder Traversal
// Deleting a node

#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *l, *r;
};
// Create a node
struct node *newNode(int data) 
{
struct node *temp = (struct node *)malloc(sizeof(struct node));
temp->value = data;
temp->l = temp->r = NULL;
return temp;
}

// Inorder Traversal
void inorder(struct node *root) 
{
if (root != NULL)
{
inorder(root->l);
printf("%d -> ", root->value);
inorder(root->r);
}
}

// Insert a node
struct node *insert(struct node *node, int value)
{
if (node == NULL) return newNode(value);
if (value < node->value)
node->l = insert(node->l, value);
else
node->r = insert(node->r, value);
return node;
}

// Find the inorder successor
struct node *minValueNode(struct node *node)
{
struct node *current = node;
// Find the leftmost leaf
while (current && current->l != NULL)
current = current->l;
 return current;
}

// Deleting a node
struct node *delete(struct node *root, int value)
{
if (root == NULL) return root;
if (value < root->value)
root->l = delete(root-> l, value);
else if (value > root->value)
root->r = delete(root-> r, value);
else 
{
if (root->l == NULL)
{
struct node *temp = root->r;
free(root);
return temp;
} 
else if (root->r == NULL)
{
struct node *temp = root->l;
free(root);
return temp;
}
// If the node has two children
struct node *temp = minValueNode(root->r);
// Place the inorder successor in position of the node to be deleted
root->value = temp->value;
// Delete the inorder successor
root->r = delete(root->r, temp->value);
}
return root;
}
int main() 
{
struct node *root = NULL;
root = insert(root, 5);
root = insert(root, 2);
root = insert(root, 9);
root = insert(root, 5);
root = insert(root, 8);
root = insert(root, 11);
root = insert(root, 21);
root = insert(root, 4);
printf("Inorder traversal: ");
inorder(root);
printf("\nAfter deleting 11\n");
root = delete(root, 11);
printf("Inorder traversal: ");
inorder(root);
}
