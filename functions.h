#pragma once

#include "PQInterface.h"
typedef char* word;

int cmpfunc(const void *, const void *);
word change(word, int, char);
NodePointer Similar(word, word*, int);
void Convert(word, word, word*, int);
