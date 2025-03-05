#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

int main()
{
  struct Node *firstNode = NULL;
  struct Node *secondNode = NULL;

  firstNode = (struct Node *)malloc(sizeof(struct Node));
  secondNode = (struct Node *)malloc(sizeof(struct Node));

  firstNode->data = 1;
  firstNode->next = secondNode;

  secondNode->data = 2;
  secondNode->next = NULL;

  printf("%d => %d", firstNode->data, secondNode->data);
  return 0;
}