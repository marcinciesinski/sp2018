// Napisz program, który wyliczy sumę liczb naturalnych
// od 1 do liczby n podanej przez użytkownika.
// Kiedy użytkownik poda liczbę mniejszą niż 1, to program
// powinien wypisać stosowny komunikat o błędzie.

#include <stdio.h>

void numberInput(int *number);
int numberSum(int number);
void printResult(int number, int result);
void printWarning();

int main()
{
  static int number;
  printf("Program wylicza sumę liczb naturalnych od 1\ndo podanej przez uzytkownika liczby..\n");
  printf("Wprowadz liczbę na ktorej sumowanie ma się zakonczyc:\n");
  numberInput(&number);
  printResult(number, numberSum(number));
}

void numberInput(int *number)
{
  scanf("%d", number);
}

int numberSum(int number)
{
  int result;
  if (number < 1)
    printWarning();
  int a = 1;
  result = 0;
  while (a <= number)
  {
    result += a;
    a++;
  }
  return result;
}

void printWarning()
{
  printf("Proszę podać liczbę naturalną większą od 1 aby sumowanie przebiegło prawidłowo\n");
}

void printResult(int number, int result)
{
  printf("Suma liczb od 1 do %d wynosi: %d\n", number, result);
}