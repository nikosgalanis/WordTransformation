#pragma once

#include "PQTypes.h"
/* defines types PQItem and PriorityQueue */
typedef char* word;

PriorityQueue* Initialize (PriorityQueue *);
int Empty (PriorityQueue *);
int Full (PriorityQueue *);
PQListNode *SortedInsert(PQItem, PQListNode *, word);
void Insert (PQItem, PriorityQueue *,word);
PQItem Remove (PriorityQueue *);
