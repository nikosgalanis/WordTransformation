#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

typedef char* word;

int cmpfunc(const void *p1, const void *p2) {
  return strcmp(* (char * const *) p1, * (char * const *) p2);
}

/*return the position of the word in the array, if found*/
int binsearch(word w, int n, word* array) {
  int cond, low, high, mid;
  low = 0;
  high = n-1;
  while (low <= high) {
    mid = (low+high)/2;
    if ((cond = strcmp(w, array[mid])) < 0)
      high = mid-1;
    else if (cond > 0)
      low = mid+1;
    else return mid;
  }
  return -1;
}

void visited(word w, word* array, char* bool_aray){
  /*we are sure that the word is in the dictionary so we can handle an endless loop(that we will evemtually break)*/
  for(int i = 0 ; i < 50000; i++){
    if(strcmp(w,array[i]) == 0){
      bool_aray[i] = 1;
      return;
    }
  }
}

/*change the n-th letter of the word*/
word change(word a, int index, char letter){
  int length = strlen(a);
  word new = malloc((length+1)*sizeof(char));
  strcpy(new,a);
  if(a[index] != letter){
    new[index] = letter;
    return new;
  }
  else{
    /*if the word is not to be changed, we do not want in in the list as a doublicate*/
    return "_";
  }
}

/*generate a list of the words that differ from the given word, only by 1 letter*/
NodePointer Similar(word w, word* word_array, int n_lines,word goal, int* done) {
  int length = strlen(w);
  NodePointer list = NULL;
  for(int i = 0; i < length; i++){
    for(char l = 'a'; l <= 'z'; l++){
      word new = change(w,i,l);
      if(bsearch(&new, word_array, n_lines, sizeof(char*),cmpfunc) != NULL) {
        if(strcmp(goal,new) == 0){
          *done = 1;
          return NULL;
        }
        InsertFirst(new, &list);
      }
    }
  }
  return list;
}
/*Convert function*/
void Convert(word start, word end, word*word_array, int n_lines){

  PriorityQueue* queue = Initialize(queue);

  /*create and allocate space for a pseudo-boolean array to determine whether or not we have allready traversed a word*/
  char* explored = malloc(n_lines*sizeof(char));
  for(int i = 0; i < n_lines; i++)
    explored[i] = 0;

  NodePointer initial = NULL;                                                   //Initialize a list that contains only the first word
  InsertFirst(end, &initial);
  visited(end, word_array, explored);                                           //and mark it as visited

  Insert(initial, queue,start);
  word new = malloc(strlen(start)*sizeof(char));

  int step_count = 0;                                                           //variable to store the total steps to get to our goal
  int done = 0;                                                                 //flag to see if we are done
  while(1) {                                                                    //perform a bfs search
    NodePointer current = Remove(queue);
    word new = malloc(strlen(start)*sizeof(char));
    strcpy(new,current->word);

    step_count++;

    NodePointer children = Similar(new, word_array, n_lines,start,&done);
    if(done == 1){                                                              //if similar reached the desired word, then we are done!
      InsertFirst(start,&current);                                              //insert the final word in the list
      printf("The path from the first word to the second is: ");                //Print the list and the stats
      PrintList(current);
      printf("We took %d steps to get there\n", step_count);
      return;
    }
    while(children != NULL) {                                                   //while the list of produced words is not empty
      word child = DeleteFirstNode(&children);
      int pos = binsearch(child,n_lines,word_array);
      if(explored[pos] == 0){
        InsertFirst(child, &current);                                           //insert the Similar word in the list
        Insert(current,queue,start);                                            //insert the new list in the pq
        DeleteFirstNode(&current);                                              //delete the node from the list
        explored[pos] = 1;
      }
    }

  }

}
