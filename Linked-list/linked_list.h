#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node
{
  int data;
  struct Node *next;
};

void append(int data);
void prepend(int data);
void insert(int x, int y);
void deleteFirst();
void deleteLast();
void reverse();
void print();

#endif
