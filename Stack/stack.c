#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct Node *top = NULL;

void push(int data)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = top;
  top = newNode;
}

void pop()
{
  if (top == NULL)
  {
    printf("Stack is empty!\n");
    return;
  }

  struct Node *temp = top;
  top = top->next;
  free(temp);
}

void printStack()
{
  struct Node *temp = top;
  while (temp != NULL)
  {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}
int main()
{
  int choice, value;

  while (1)
  {
    printf("\n1. Push\n2. Pop\n3. Print\n4. Exit\nChoose: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter value: ");
      scanf("%d", &value);
      push(value);
      break;
    case 2:
      pop();
      printf("Top element removed.\n");
      break;
    case 3:
      printStack();
      break;
    case 4:
      return 0;
    default:
      printf("Invalid choice!\n");
    }
  }
}