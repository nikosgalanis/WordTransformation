#pragma once

#include "ListInterface.h"
typedef char* word;

int cmpfunc(const void *, const void *);
word change(word, int, char);
NodePointer Similar(word w, word* word_array, int n_lines);
