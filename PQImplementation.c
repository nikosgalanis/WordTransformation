/* This is the file PQImplementation.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PQInterface.h"

/* Now we give all the details of the functions */
/* declared in the interface file together with */
/* local private functions.                     */

int differs(word curr, word goal){                                              //Implementation of the heuristic function
  int l = strlen(curr);
  int dif = 0;
  for(int i = 0; i < l; i++){
    if(curr[i] != goal[i]) dif++;
  }
  return dif;
}

int f(PQItem current, word goal){                                               //Implementation of A* algorithm for sorted insertion
  int g = Length(current) - 1;
  int h = differs(current->word, goal);
  return(g+h);
}


void Initialize(PriorityQueue *PQ) {                                            //Initialize a pq
   PQ->Count = 0;
   PQ->ItemList = NULL;
}

int Empty(PriorityQueue *PQ) {                                                  //Determine whether the pq is empty or not
   return(PQ->Count == 0);
}


int Full(PriorityQueue *PQ) {                                                   //our PriorityQueue is never full :-)
   return(0);
}

PQListNode *SortedInsert(PQItem Item, PQListNode *P, word goal) {                          //recursive function in order to insert a new node to the PQ
   PQListNode *N;
   if ((P == NULL) || (f(Item,goal) <= f(P->NodeItem,goal))) {
      N = malloc(sizeof(PQListNode));
      N->NodeItem = Item;
      N->Link = P;
      return(N);
   } else {
      P->Link = SortedInsert(Item, P->Link,goal);
      return(P);
   }
}


void Insert(PQItem Item, PriorityQueue *PQ,word goal) {                                   //PriorityQueue insertion
   if (!Full(PQ)) {
     PQ->Count++;
     PQ->ItemList = SortedInsert(Item, PQ->ItemList, goal);
   }
}

PQItem Remove(PriorityQueue *PQ) {                                              //Pop the first item from the queue
   PQItem temp;
   if (!Empty(PQ)){
     temp = PQ->ItemList->NodeItem;
     PQ->ItemList = PQ->ItemList->Link;
     PQ->Count--;
     return(temp);
   }
}
