#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../headers/ListInterface.h"

void PrintList(NodeType *L) {
      NodeType *N;

      printf("(");
      N = L;
      while(N != NULL) {
         printf("%s", N->word);
         N = N->Link;
         if (N != NULL) printf("->");
      }
      printf(")\n");
}


char* DeleteFirstNode(NodeType** L) {
  char* first = NULL;
  NodeType* temp = NULL;
    if(*L != NULL) {
      temp = (*L);
      int l = strlen((*L)->word);
      first = malloc((l+1)*sizeof(char));
      if(first == NULL) printf("Stack overflow!!\n");

      strcpy(first, (*L)->word);
      (*L) = (*L)->Link;
    }
    return first;
}

void InsertFirst(char* w,NodeType **L) {
      NodeType *N;
      int w_length = strlen(w);
      N = malloc(sizeof(NodeType));
      if(N == NULL) printf("Stack overflow!!\n");
      N->word = malloc((w_length+1)*sizeof(char));
      strcpy(N->word, w);
      N->Link = (*L);
      (*L) = N;
}

int Length(NodeType* L) {
  int count = 0;
  NodeType* temp = L;
  while(temp != NULL) {
    count++;
    temp = temp->Link;
  }
  return count;
}
