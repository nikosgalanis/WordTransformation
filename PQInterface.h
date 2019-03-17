#pragma once

#include "PQTypes.h"
/* defines types PQItem and PriorityQueue */
typedef char* word;

void Initialize (PriorityQueue *);
int Empty (PriorityQueue *);
int Full (PriorityQueue *);
void Insert (PQItem, PriorityQueue *);
PQItem Remove (PriorityQueue *);
