// After feeling like you've been falling for a few minutes, 
// you look at the device's tiny screen. "Error: Device must be 
// calibrated before first use. Frequency drift detected. 
// Cannot maintain destination lock." Below the message, 
// the device shows a sequence of changes in frequency 
// (your puzzle input). A value like +6 means the current 
// frequency increases by 6; a value like -3 means the 
// current frequency decreases by 3.

// For example, if the device displays frequency changes 
// of +1, -2, +3, +1, then starting from a frequency of zero,
// the following changes would occur:

//     Current frequency  0, change of +1; resulting frequency  1.
//     Current frequency  1, change of -2; resulting frequency -1.
//     Current frequency -1, change of +3; resulting frequency  2.
//     Current frequency  2, change of +1; resulting frequency  3.

#include <stdio.h>

int frequency(int *tab_lenght);
void print_freq_solution(int freq_sum);

int main()
{
  int freq, tab_lenght;
  freq=frequency(&tab_lenght);
  print_freq_solution(freq);
  printf("%d\n", tab_lenght);
  
}

int frequency(int *tab_lenght){
  FILE *puzzle_input;
  puzzle_input = fopen("freq.txt", "r");
  
  *tab_lenght=0;
  int n, freq_sum=0;

  while(fscanf(puzzle_input, "%d", &n) != EOF){
    (*tab_lenght)++;
    freq_sum += n;

  }
  return freq_sum;
}

void print_freq_solution(int freq_sum){
  fprintf(stderr, "%d\n", freq_sum);
}

// typedef struct {
//   int *array;
//   size_t used;
//   size_t size;
// } Array;

// void initArray(Array *a, size_t initialSize) {
//   a->array = (int *)malloc(initialSize * sizeof(int));
//   a->used = 0;
//   a->size = initialSize;
// }

// void insertArray(Array *a, int element) {
//   // a->used is the number of used entries, because a->array[a->used++] updates a->used only *after* the array has been accessed.
//   // Therefore a->used can go up to a->size 
//   if (a->used == a->size) {
//     a->size *= 2;
//     a->array = (int *)realloc(a->array, a->size * sizeof(int));
//   }
//   a->array[a->used++] = element;
// }

// void freeArray(Array *a) {
//   free(a->array);
//   a->array = NULL;
//   a->used = a->size = 0;
// }