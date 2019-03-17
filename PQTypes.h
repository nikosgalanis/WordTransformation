#pragma once

#include "ListTypes.h"

typedef NodeItem* PQItem;

typedef struct PQNodeTag {
           PQItem   NodeItem;
           struct PQNodeTag *Link;
        } PQListNode;

typedef struct {
           int Count;
           PQListNode *ItemList;
        } PriorityQueue;
