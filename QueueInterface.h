#pragma once
/* This is the file QueueInterface.h   */

#include "QueueTypes.h"

void InitializeQueue(Queue *);
int Empty(Queue *);
int Full(Queue *);
void Insert(ItemType , Queue *);
void Remove(Queue *, ItemType *);
