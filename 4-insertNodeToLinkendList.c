#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

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
  while (q->next->data != x)
  {
    q = q->next;
  }
  struct Node *before = (struct Node *)malloc(sizeof(struct Node));
  before = q->next;
  q->next = insertData;
  insertData->next = before;
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
    printf("5. Exit\n");
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
      printf("Exiting...\n");
      exit(0);

    default:
      printf("Invalid choice, please try again.\n");
    }
  }

  return 0;
}
