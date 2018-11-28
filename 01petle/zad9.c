// Napisz program monożący liczby tak jak to pokazano w tym filmiku
// A Night Of Numbers – Go Forth And Multiply.
// (etiopska metoda mnożenia)

#include <stdio.h>

void etiopianMultiply();

int main()
{
  printf("Program realizuje mnożenie metodą używaną w starożytnej etiopii..\n");
  printf("proszę podać dwie liczby całkowite które mają być pomnożone oddzielone spacją:\n");
  etiopianMultiply();
}

void etiopianMultiply()
{
  int firstNumber = 0;
  int secondNumber = 0;
  int firstNumberSplitStep = 0;
  int secondNumberMultiplyStep = 1;
  int result = 0;
  scanf("%d %d", &firstNumber, &secondNumber);
  int firstAction = firstNumber;
  int seconAction = firstNumber;
  while (firstAction > 1)
  {
    firstAction = firstAction / 2;
    firstNumberSplitStep++;
  }
  int resultOfMultiplyTab[firstNumberSplitStep + 1];
  int firstNumberSplitStepTab[firstNumberSplitStep + 1];
  firstNumberSplitStepTab[0] = firstNumber;
  for (int i = 0; i < firstNumberSplitStep + 1; i++)
  {
    firstNumberSplitStepTab[i + 1] = seconAction / 2;
    seconAction = seconAction / 2;
    resultOfMultiplyTab[i] = secondNumber * secondNumberMultiplyStep;
    secondNumberMultiplyStep *= 2;
  }
  for (int i = 0; i < firstNumberSplitStep + 1; i++)
  {
    if (firstNumberSplitStepTab[i] % 2 != 0)
      result += resultOfMultiplyTab[i];
  }
  printf("Wynikiem mnożenia %d * %d jest: %d\n", firstNumber, secondNumber, result);
}
