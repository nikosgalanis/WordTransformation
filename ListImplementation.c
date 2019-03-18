#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ListInterface.h"

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
    if(*L != NULL) {
      NodePointer temp = (*L);
      int l = strlen((*L)->word);
      first = malloc((l+1)*sizeof(char));
      strcpy(first,(*L)->word);
      (*L) = (*L)->Link;
      //free((temp)->word);
      //temp->Link = NULL;
      //free(temp);
    }
    return first;
}

void InsertFirst(char* w,NodeType **L) {
      NodeType *N;
      int w_length = strlen(w);
      N = malloc(sizeof(NodeType));
      N->word = malloc((w_length+1)*sizeof(char));
      strcpy(N->word, w);
      N->Link = (*L);
      (*L) = N;
}

int Length(NodeType* L){
  int count = 0;
  NodeType* temp = L;
  while(temp != NULL){
    count++;
    temp = temp->Link;
  }
  return count;
}
