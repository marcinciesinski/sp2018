// 4. Napisać program obliczający silnię z podanej,
//  niezbyt dużej, liczby naturalnej.

#include <stdio.h>

void numberImput(int *number);
void factorial(int number);

int main()
{
  int number;
  printf("Program służy do obliczania silni z niezbyt dużej liczby naturalnej\n");
  printf("Proszę podać liczbę naturalną:\n ");
  numberImput(&number);
  factorial(number);
}
void numberImput(int *number)
{
  scanf("%d", number);
}

void factorial(int number)
{
  int result = 1;
  int numberOutput = number;
  if (number < 0)
    printf("Silnia jest iloczynem liczb naturalnych dodatnich...\n");
  else
  {
    while (number > 0)
    {
      result *= number;
      number--;
      if (result < 0)
      {
        printf("przekroczono zasięg obliczeń... \n");
        break;
      }
    }
    if (result > 0)
      printf("%d! = %d \n", numberOutput, result);
  }
}