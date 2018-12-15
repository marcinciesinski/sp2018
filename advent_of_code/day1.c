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

int frequences();
void printSolution(int answ);

int main()
{
  int freq; // solution

  freq = frequences();
  
  printSolution(freq);
}

int frequences(){
  int n, freq = 0;

  while(fscanf(stdin, "%d" , &n) != EOF )
  {
    freq += n;
    fprintf(stdout, "%d\n", n);
  }
  return freq;
}

void printSolution(int answ){
  fprintf(stderr, "%d\n", answ);
}


