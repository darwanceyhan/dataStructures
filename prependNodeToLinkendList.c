#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct Node *start = NULL;
struct Node *q = NULL;

void prepend(int data)
{
  struct Node *appendData = (struct Node *)malloc(sizeof(struct Node));

  appendData->data = data;
  appendData->next = start;
  start = appendData;
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
  int data;
  while (1)
  {
    printf("Enter a number: ");
    scanf("%d", &data);
    prepend(data);
    print();
  }
  return 0;
}
