#pragma once

#include "ListInterface.h"

typedef NodeType* PQItem;

typedef struct PQNodeTag {
           PQItem   NodeItem;
           struct PQNodeTag *Link;
        } PQListNode;

typedef struct {
           int Count;
           PQListNode *ItemList;
        } PriorityQueue;
