#pragma once

/* The code is from Chapter 2 of the book "Data Structures, Algorithms and Software Principles in C" */
typedef struct NodeTag {
                        char* word;
                        struct NodeTag *Link;
                } NodeType;
typedef NodeType *NodePointer;
