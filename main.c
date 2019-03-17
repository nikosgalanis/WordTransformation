#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PQTypes.h"
#include "ListTypes.h"
#include "functions.h"


typedef char* word;

int main(void){
  FILE* input = fopen("words","r");
  char ch;
  int n_lines=0,w_length=0,max_w_length=0;

  while((ch = getc(input)) != EOF){
    if (ch != '\n') w_length++;
    else {
      n_lines++;
      if (w_length > max_w_length) max_w_length = w_length;
      w_length = 0;
    }
  }
  rewind(input);
  word* word_array;
  if ((word_array = malloc(n_lines * sizeof(char*))) == NULL){
    printf("Not enough memory!\n");
    return -1;
  }

  for(int i = 0; i < n_lines; i++){
    if((word_array[i] = malloc((max_w_length+1) * sizeof(char))) == NULL){
      printf("Not enough memory!\n");
      return -1;
    }
    fscanf(input,"%s",word_array[i]);
  }

  qsort(word_array, n_lines , sizeof(char*), cmpfunc);

  fclose(input);

  Convert("table", "acton", word_array, n_lines);


  for(int i = 0; i < n_lines; i++){
    free(word_array[i]);
  }
  free(word_array);

  return 0;
}
