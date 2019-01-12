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

int frequency(int *tab_lenght);
void print_freq_solution(int freq_sum);
void search_for_duplicate();

int main()
{
	int freq, tab_lenght;
	freq = frequency(&tab_lenght);
	print_freq_solution(freq);
	search_for_duplicate();
}

int frequency(int *tab_lenght)
{
	FILE *puzzle_input;
	puzzle_input = fopen("freq.txt", "r");

	*tab_lenght = 0;
	int n, freq_sum = 0;

	while (fscanf(puzzle_input, "%d", &n) != EOF)
	{
		(*tab_lenght)++;
		freq_sum += n;
	}
	return freq_sum;
	fclose(puzzle_input);
}

void print_freq_solution(int freq_sum)
{
	fprintf(stderr, "rozwiązaniem pierwszej części zadania jest : %d\n", freq_sum);
}

void search_for_duplicate()
{
	// zainicjować zmienną int i za każdym przejsciem pętli 
	// powiększać tablicę o jej oryginalną wartość..
	// jeśli liczba będzie znaleziona to zakończ.

	int all_freq_in_tab[200000];
	all_freq_in_tab[0] = 0;
	int n, freq_sum = 0, i = 1;
	int first_duplicate = 0;

	while (first_duplicate == 0)
	{
		FILE *puzzle_input;
		puzzle_input = fopen("freq.txt", "r");

		while (fscanf(puzzle_input, "%d", &n) != EOF)
		{
			freq_sum += n;
			all_freq_in_tab[i] = freq_sum;

			for (int a = 0; a < i; a++)
			{
				if (all_freq_in_tab[a] == freq_sum)
				{
					first_duplicate = freq_sum;
					printf("Element na pozycji %d powtórzył się z elementem na pozycji %d w tablicy przechowywującej wyniki sumowania.\n", a, i);
					printf("Pierwsza powtórzona liczba i rozwiązanie drugiej części zadania to: %d \n", freq_sum);
					exit(0);
				}
			}
			i++;
		}
		fclose(puzzle_input);
	}
}