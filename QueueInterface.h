#pragma once
/* This is the file QueueInterface.h   */

#include "QueueTypes.h"

void InitializeQueue(Queue *);
int Empty(Queue *);
int Full(Queue *);
void Push(ItemType , Queue *);
void Pop(Queue *, ItemType *);
ItemType* Head(Queue*);
ItemType* Tail(Queue*);
