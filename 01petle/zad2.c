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

<<<<<<< HEAD
void chestPrinter();

int main()
{
  printf("Program drukuje szachownicę:");
  chestPrinter();
}

void chestPrinter()
=======
void chestPrint();

int main()
{
  chestPrint();
}

void chestPrint()
>>>>>>> 2c89fddea958bed23cd9a376b245a5915be79b44
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
