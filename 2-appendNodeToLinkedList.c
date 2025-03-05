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
  if (appendData == NULL) // malloc başarısız olabilir
  {
    printf("Memory allocation failed\n");
    return;
  }

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
    append(data);
    print();
  }
  return 0;
}
