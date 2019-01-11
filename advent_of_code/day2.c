// To make sure you didn't miss any, you scan the likely candidate boxes again,
// counting the number that have an ID containing exactly two of any letter
// and then separately counting those with exactly three of any letter.
// You can multiply those two counts together to get a rudimentary checksum
// and compare it to what your device predicts.

// For example, if you see the following box IDs:

//     abcdef contains no letters that appear exactly two or three times.
//     bababc contains two a and three b, so it counts for both.
//     abbcde contains two b, but no letter appears exactly three times.
//     abcccd contains three c, but no letter appears exactly two times.
//     aabcdd contains two a and two d, but it only counts once.
//     abcdee contains two e.
//     ababab contains three a and three b, but it only counts once.

// Of these box IDs, four of them contain a letter which appears exactly twice, and three of them contain a letter which appears exactly three times. Multiplying these together produces a checksum of 4 * 3 = 12.

// What is the checksum for your list of box IDs?

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