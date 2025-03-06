#ifndef STACK_H
#define STACK_H

struct Node
{
  int data;
  struct Node *next;
};

void push(int data);
void pop();
void printStack();

#endif
