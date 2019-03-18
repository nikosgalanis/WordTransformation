#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "PQTypes.h"
#include "ListTypes.h"
#include "functions.h"


typedef char* word;

int main(void){
  FILE* input = fopen("words","r");                                             //open the file
  char ch;
  int n_lines=0,w_length=0,max_w_length=0;

  while((ch = getc(input)) != EOF){                                             //Determine the maximum length of the words, and the number of words in the file
    if (ch != '\n') w_length++;
    else {
      n_lines++;
      if (w_length > max_w_length) max_w_length = w_length;
      w_length = 0;
    }
  }
  rewind(input);                                                                //rewind the file, in order to read the words

  word* word_array;                                                             //create and allocate space for an array to store the words
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

  qsort(word_array, n_lines , sizeof(char*), cmpfunc);                          //sort the array, in order to perform binary search

  fclose(input);                                                                //close the useless file

  word first = malloc((max_w_length+1)*sizeof(char));                               //allocate space for the 2 words
  word second = malloc((max_w_length+1)*sizeof(char));

  printf("Give the first word\n"); scanf("%s", first);
  printf("Give the second word\n"); scanf("%s", second);
  /*if the user inserts words that are not of the same length, or that they are not in the dictionary, display an error message and ask again*/
  while(bsearch(&first, word_array, n_lines, sizeof(char*),cmpfunc) == NULL
      || bsearch(&second, word_array, n_lines, sizeof(char*),cmpfunc) == NULL
      || (strlen(first) != strlen(second))){
        printf("Wrong input, try again!\n");
        printf("Give the first word\n"); scanf("%s\n", first);
        printf("Give the second word\n"); scanf("%s\n", second);
      }

  double sttime = ((double) clock())/CLOCKS_PER_SEC;                            //determine the time before, and after the opperation

  Convert(first, second, word_array, n_lines);

  double endtime = ((double) clock())/CLOCKS_PER_SEC;

  printf("The convertion took us %.4f seconds\n", endtime-sttime);

  // NodePointer list = Similar("cat",word_array,n_lines);
  // DeleteFirstNode(&list);
  // PrintList(list);

  for(int i = 0; i < n_lines; i++){                                             //free the array
    free(word_array[i]);
  }
  free(word_array);

  return 0;
}
