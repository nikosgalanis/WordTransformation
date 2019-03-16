#pragma once
#include "ListTypes.h"

/* function prototypes */
void InsertFirst(char*, NodeType **);
void InsertLast(char *, NodeType **);
void DeleteLastNode(NodeType **);
char* DeleteFirstNode(NodeType** L);
NodeType *ListSearch(char *, NodeType *);
void PrintList(NodeType *);
