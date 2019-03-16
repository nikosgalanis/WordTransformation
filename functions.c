#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

typedef char* word;

int cmpfunc(const void *p1, const void *p2) {
  return strcmp(* (char * const *) p1, * (char * const *) p2);
}

word change(word a, int index, char letter){
  int length = strlen(a);
  word new = malloc(length*sizeof(char));
  strcpy(new,a);
  if(a[index] != letter){
    new[index] = letter;
    return new;
  }
  else{
  //if the word is not to be changed, we do not want in in the list as a doublicate
    return "___";
  }
}

NodePointer Similar(word w, word* word_array, int n_lines) {
  int length = strlen(w);
  printf("length is %d\n", length);
  NodePointer list = NULL;
  for(int i = 0; i < length; i++){
    for(char l = 'a'; l <= 'z'; l++){
      word new = change(w,i,l);
      if(bsearch(&new, word_array, n_lines, sizeof(char*),cmpfunc) != NULL) {
        InsertFirst(new, &list);
      }
    }
  }
  PrintList(list);
  return list;
}
