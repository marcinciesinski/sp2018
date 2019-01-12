# Link:
* [Advent of Code]( https://adventofcode.com/ ).

# Aby skompilować programy należy w konsoli wpisać: 
## make / make "day1" <-- jeśli chcesz skompilować pojedynczy program.

#

# DAY 1

  Alternatywny sposob pobierania danych z pliku ->
##  ./day1 < day1.txt > frequences.txt
  Sortowanie rezultatow w konsoli ->
##  sort frequences.txt | uniq -D

# Treść zadania 1:

## Część 1:

After feeling like you've been falling for a few minutes,
you look at the device's tiny screen. "Error: Device must be
calibrated before first use. Frequency drift detected.
Cannot maintain destination lock." Below the message,
the device shows a sequence of changes in frequency
(your puzzle input). A value like +6 means the current
frequency increases by 6; a value like -3 means the
current frequency decreases by 3.

For example, if the device displays frequency changes
of +1, -2, +3, +1, then starting from a frequency of zero,
the following changes would occur:

    Current frequency  0, change of +1; resulting frequency  1.
    Current frequency  1, change of -2; resulting frequency -1.
    Current frequency -1, change of +3; resulting frequency  2.
    Current frequency  2, change of +1; resulting frequency  3.

## Część 2:

You notice that the device repeats the same frequency change list
over and over. To calibrate the device, you need to find the first
frequency it reaches twice.

For example, using the same list of changes above, the device
would loop as follows:

    Current frequency  0, change of +1; resulting frequency  1.
    Current frequency  1, change of -2; resulting frequency -1.
    Current frequency -1, change of +3; resulting frequency  2.
    Current frequency  2, change of +1; resulting frequency  3.
    (At this point, the device continues from the start of the list.)
    Current frequency  3, change of +1; resulting frequency  4.
    Current frequency  4, change of -2; resulting frequency  2, 
    which has already been seen.

In this example, the first frequency reached twice is 2.
Note that your device might need to repeat its list of
frequency changes many times before a duplicate frequency
is found, and that duplicates might be found while in the
middle of processing the list.

# KOD:

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

### deklaracja zmiennych w funkcji main

    int main()
    { 
      int freq, tab_lenght;
      freq = frequency(&tab_lenght);
      print_freq_solution(freq);
      search_for_duplicate();
    }

### funkcja licząca sumę liczb zczytanych z pliku:

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

### funkcja wypisująca wynik:

    void print_freq_solution(int freq_sum)
    {
      fprintf(stderr, "rozwiązaniem pierwszej części zadania jest : %d\n", freq_sum);
    }

### funkcja szukająca duplikatu liczby. Skanuje i zapisuje wyniki w tablicy tak długo aż znajdzie duplikat.

    void search_for_duplicate()
    {
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

# DAY 2

# Treść zadania 1:

## Część 1:

To make sure you didn't miss any, you scan the likely candidate boxes again,
counting the number that have an ID containing exactly two of any letter
and then separately counting those with exactly three of any letter.
You can multiply those two counts together to get a rudimentary checksum
and compare it to what your device predicts.

For example, if you see the following box IDs:

    abcdef contains no letters that appear exactly two or three times.
    bababc contains two a and three b, so it counts for both.
    abbcde contains two b, but no letter appears exactly three times.
    abcccd contains three c, but no letter appears exactly two times.
    aabcdd contains two a and two d, but it only counts once.
    abcdee contains two e.
    ababab contains three a and three b, but it only counts once.

Of these box IDs, four of them contain a letter which appears exactly twice, and three of them contain a letter which appears exactly three times. Multiplying these together produces a checksum of 4 * 3 = 12.

What is the checksum for your list of box IDs?

## Część 2:

# IN PROGRESS

# KOD:

    #include <stdio.h>
    #include <stdlib.h>

    void dataInputAndCount();

    int main()
    {
      dataInputAndCount();
    }

    void dataInputAndCount()
    {
      FILE *puzzle_input;
      puzzle_input = fopen("puzzleInputDay2.txt", "r");

      char str[50] = {0};
      char znak_porownywany, pierwszy_znak_powtarzajacy_sie = ' ', drugi_znak_powtarzajacy_sie = ' ';
      int c = 0, count = 1;
      int podwojne_zliczenie = 0, potrojne_zliczenie = 0;
      int repeat_2 = 0, repeat_3 = 0;

      while (fgets(str, 50, puzzle_input) != NULL)
      {
        while (str[c] != '\0')
        {
          znak_porownywany = str[c];
          if (znak_porownywany != pierwszy_znak_powtarzajacy_sie && znak_porownywany != drugi_znak_powtarzajacy_sie)
          {
            for (int i = c + 1; str[i] != '\0'; i++)
            {
              if (pierwszy_znak_powtarzajacy_sie != ' ')
                drugi_znak_powtarzajacy_sie = pierwszy_znak_powtarzajacy_sie;
              if (znak_porownywany == str[i])
              {
                pierwszy_znak_powtarzajacy_sie = znak_porownywany;
                count += 1;
              }
            }
            if (count == 2 && podwojne_zliczenie == 0)
            {
              podwojne_zliczenie++;
              repeat_2++;
            }

            if (count == 3 && potrojne_zliczenie == 0)
            {
              potrojne_zliczenie++;
              repeat_3++;
            }
          }
          count = 1;
          c++;
        }
        pierwszy_znak_powtarzajacy_sie = ' ';
        drugi_znak_powtarzajacy_sie = ' ';
        podwojne_zliczenie = potrojne_zliczenie = 0;
        c = 0;
      }
      fclose(puzzle_input);
      printf("2 powtorzen jest: %d \n", repeat_2);
      printf("3 powtorzen jest: %d \n", repeat_3);
      printf("ich iloczyn wynosi %d \n", repeat_2 * repeat_3);
    }

