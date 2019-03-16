#pragma once
/* This is the file QueueTypes.h */

#include "ListTypes.h"

typedef NodePointer ItemType;
/* the item type can be arbitrary */

typedef struct QueueNodeTag {
                     ItemType Item;
                     struct QueueNodeTag *Link;
                } QueueNode;

typedef struct {
                    QueueNode *Front;
                    QueueNode *Rear;
               } Queue;
