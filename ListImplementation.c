#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ListInterface.h"

void InsertNewLastNode(char *w, NodeType **L)
{
      NodeType *N, *P;
      int w_length = strlen(w);
      N = (NodeType *)malloc(sizeof(NodeType));
      N->word = malloc((w_length+1)*sizeof(char));
      strcpy(N->word, w);
      N->Link = NULL;

      if (*L == NULL) {
         *L = N;
      } else {
         P = *L;
         while (P->Link != NULL) P = P->Link;
         P->Link = N;
      }

}



void PrintList(NodeType *L)
{
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


char* DeleteFirstNode(NodeType** L){
    if(*L != NULL) {
      NodeType* temp = (*L);
    }
}

void DeleteLastNode(NodeType **L)
{
      NodeType *PreviousNode, *CurrentNode;

      if (*L != NULL) {
         if ((*L)->Link == NULL) {
            free(*L);
            *L = NULL;
         } else {
            PreviousNode = *L;
            CurrentNode = (*L)->Link;
            while (CurrentNode->Link != NULL){
               PreviousNode = CurrentNode;
               CurrentNode = CurrentNode->Link;
            }
            PreviousNode->Link = NULL;
            free(CurrentNode);
         }
      }
}


void InsertFirst(char* w,NodeType **L)
{
      NodeType *N;
      int w_length = strlen(w);
      N = (NodeType *)malloc(sizeof(NodeType));
      N->word = malloc((w_length+1)*sizeof(char));
      strcpy(N->word, w);
      N->Link = (*L);
      (*L) = N;
}



NodeType *ListSearch(char *w, NodeType *L)
{
      NodeType *N;

      N = L;
      while (N != NULL) {
        if (strcmp(N->word,w) == 0) {
           return N;
        } else {
           N = N->Link;
        }
      }
      return N;
}
