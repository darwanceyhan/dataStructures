#include <stdio.h>
#include "hash_table.h"
#define TABLE_SIZE 10

int hashTable[TABLE_SIZE] = {0};

int hashFunction(int key)
{
  return key % TABLE_SIZE;
}

void insert(int key)
{
  int index = hashFunction(key);
  hashTable[index] = key;
}

int search(int key)
{
  int index = hashFunction(key);
  return (hashTable[index] == key);
}

void printHashTable()
{
  for (int i = 0; i < TABLE_SIZE; i++)
  {
    printf("Index %d: %d\n", i, hashTable[i]);
  }
}

int main()
{
  insert(15);
  insert(25);
  insert(35);

  printHashTable();

  if (search(25))
    printf("25 bulundu!\n");
  else
    printf("25 bulunamadı!\n");

  return 0;
}