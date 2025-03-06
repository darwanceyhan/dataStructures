#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

struct Node *start = NULL;
struct Node *q = NULL;

void append(int data)
{
  struct Node *appendData = (struct Node *)malloc(sizeof(struct Node));

  appendData->data = data;
  appendData->next = NULL;

  if (start == NULL)
  {
    start = appendData;
  }
  else
  {
    q = start;
    while (q->next != NULL)
    {
      q = q->next;
    }
    q->next = appendData;
  }
}

void prepend(int data)
{
  struct Node *appendData = (struct Node *)malloc(sizeof(struct Node));

  appendData->data = data;
  appendData->next = start;
  start = appendData;
}

void insert(int x, int y)
{
  struct Node *insertData = (struct Node *)malloc(sizeof(struct Node));

  insertData->data = y;
  q = start;

  while (q != NULL && q->data != x)
  {
    q = q->next;
  }

  if (q != NULL)
  {
    struct Node *before = q->next;
    q->next = insertData;
    insertData->next = before;
  }
  else
  {
    printf("Value %d not found in the list.\n", x);
    free(insertData);
  }
}

void deleteFirst()
{
  if (start != NULL)
  {
    struct Node *second = start->next;
    free(start);
    start = second;
  }
  else
  {
    printf("List is empty.\n");
  }
}

void deleteLast()
{
  if (start != NULL)
  {
    if (start->next == NULL)
    {
      free(start);
      start = NULL;
      return;
    }

    q = start;
    while (q->next->next != NULL)
    {
      q = q->next;
    }
    free(q->next);
    q->next = NULL;
  }
  else
  {
    printf("List is empty.\n");
  }
}

void reverse()
{
  struct Node *prev = NULL, *current = start, *next = NULL;

  while (current != NULL)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  start = prev;
}

void print()
{
  q = start;
  while (q != NULL)
  {
    printf("%d => ", q->data);
    q = q->next;
  }
  printf("NULL\n");
}

int main()
{
  int data, x, y, choice;

  while (1)
  {
    printf("\nMenu:\n");
    printf("1. Append (Add to the end)\n");
    printf("2. Prepend (Add to the beginning)\n");
    printf("3. Insert (Insert after a node)\n");
    printf("4. Print the list\n");
    printf("5. Delete (Delete last node)\n");
    printf("6. Delete (Delete first node)\n");
    printf("7. Exit\n");
    printf("8. Reverse (Ters çevir)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter value to append: ");
      scanf("%d", &data);
      append(data);
      printf("Element appended.\n");
      break;

    case 2:
      printf("Enter value to prepend: ");
      scanf("%d", &data);
      prepend(data);
      printf("Element prepended.\n");
      break;

    case 3:
      printf("Enter value to insert after: ");
      scanf("%d", &x);
      printf("Enter value to insert: ");
      scanf("%d", &y);
      insert(x, y);
      printf("Element inserted.\n");
      break;

    case 4:
      print();
      break;

    case 5:
      deleteLast();
      break;

    case 6:
      deleteFirst();
      break;

    case 7:
      printf("Exiting...\n");
      exit(0);

    case 8:
      reverse();
      printf("List reversed.\n");
      break;

    default:
      printf("Invalid choice, please try again.\n");
    }
  }

  return 0;
}
