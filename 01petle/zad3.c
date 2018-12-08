// Napisz program, który wczyta dwie liczby całkowite
// a i b (a<b) a następnie wypisze wszystkie liczby
// całkowite pomiędzy a i b.

#include <stdio.h>

void numberInput(int *a, int *b);
void numberOutput(int a, int b);

int main()
{
  int a, b;
  printf("Program wczytuje 2 liczby całkowite a oraz b (a<b),\na następnie wypisuje wszystkie liczby całkowite pomiędzy nimi\n");
  printf("Podaj dwie liczby rzeczywiste oddzielone spacją:\n");
  numberInput(&a, &b);
  numberOutput(a, b);
}

void numberInput(int *a, int *b)
{
  scanf("%d %d", a, b);
}

void numberOutput(int a, int b)
{
  if (a == b)
    printf("nie ma liczb całkowitych pomiędzy %d i %d\n", a, b);
  else if (a>b)
    printf("liczba a powinna być mniejsza od b \n");
  else
  {
    printf("Liczby pomiędzy %d oraz %d to: ", a, b);
    for (int i = a + 1; i < b; i++)
    {
      printf("%d ", i);
    }
    printf("\n");
  }
}