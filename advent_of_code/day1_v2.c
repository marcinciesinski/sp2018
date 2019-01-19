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
#include <stdlib.h>

#define ARRAY_LENGTH (133000)

int frequency_drift();
void print_freq_solution(int freq_sum);
void print_warning();
void print_answer_for_duplicate(int a, int i, int freq_sum);
void search_for_duplicate();
void check_for_answer(int *all_freq_in_tab, int first_duplicate);

int main()
{
  // część pierwsza zadania

  int frequency_sum;
  frequency_sum = frequency_drift();
  print_freq_solution(frequency_sum);

  // część druga zadania

  search_for_duplicate();
}

int frequency_drift()
{
  FILE *puzzle_input;
  puzzle_input = fopen("freq.txt", "r");

  int n, freq_sum = 0;

  while (fscanf(puzzle_input, "%d", &n) != EOF)
  {
    freq_sum += n;
  }
  fclose(puzzle_input);
  return freq_sum;
}

void search_for_duplicate()
{
  int *all_freq_in_tab[ARRAY_LENGTH];
  all_freq_in_tab[0] = 0;
  int *first_duplicate = 0;

  while (*first_duplicate == 0)
  {  
    check_for_answer(*all_freq_in_tab, *first_duplicate);
  }
}

void check_for_answer(int *all_freq_in_tab, int first_duplicate)
{
  FILE *puzzle_input;
  puzzle_input = fopen("freq.txt", "r");
  int n, freq_sum = 0, i = 1;

  while (fscanf(puzzle_input, "%d", &n) != EOF)
    {
      if (i > ARRAY_LENGTH)
        print_warning();
      freq_sum += n;
      all_freq_in_tab[i] = freq_sum;
      for (int a = 0; a < i; a++)
      {
        if (all_freq_in_tab[a] == freq_sum)
        {
          first_duplicate = freq_sum;
          print_answer_for_duplicate(a, i, freq_sum);
        }
      }
      i++;
    }
    fclose(puzzle_input);
}

void print_freq_solution(int freq_sum)
{
  fprintf(stderr, "rozwiązaniem pierwszej części zadania jest : %d\n", freq_sum);
}

void print_warning()
{
  printf("Przekroczono zakres tablicy w trakcie obliczeń...\nProszę ją powiększyć\n");
  exit(1);
}

void print_answer_for_duplicate(int a, int i, int freq_sum)
{
  printf("Element na pozycji %d powtórzył się z elementem na pozycji %d w tablicy przechowywującej wyniki sumowania.\n", a, i);
  printf("Pierwsza powtórzona liczba i rozwiązanie drugiej części zadania to: %d \n", freq_sum);
  exit(0);
}