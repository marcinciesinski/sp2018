// Napisz program wyświetlający poniższą szachownicę:

// * * * * * * * *
//  * * * * * * * *
// * * * * * * * *
//  * * * * * * * *
// * * * * * * * *
//  * * * * * * * *
// * * * * * * * *
//  * * * * * * * *
#include <stdio.h>

void chestPrint();

int main()
{
  chestPrint();
}

void chestPrint()
{
  int col = 8;
  int row = 8;
  for (int i = 0; i < col; i++)
  {
    printf("\n");
    if (i % 2 == 1)
      printf(" ");
    for (int i = 0; i < row; i++)
    {
      printf("*");
      printf(" ");
    }
  }
  printf("\n");
}
