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

void chestPrinter();
void printIndent(int i);
void rowPrinter(int row);

int main()
{
  printf("Program drukuje szachownicę:");
  chestPrinter();
}

void printIndent(int i)
{
  if (i % 2 == 1)
    printf(" ");
}

void rowPrinter(int row)
{
  for (int i = 0; i < row; i++)
    {
      printf("*");
      printf(" ");
    }
}

void chestPrinter()
{
  int col = 8;
  int row = 8;
  for (int i = 0; i < col; i++)
  {
    printf("\n");
    printIndent(i);
    rowPrinter(row);
  }
  printf("\n");
}
