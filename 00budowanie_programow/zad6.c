// 6. Napisz program, który wczyta liczbę rzeczywistą i
// wypisze jej pierwiastek kwadratowy. 
// W wypadku podania liczby ujemnej, 
// program powinien wypisać komunikat o błędzie oraz 
// zakończyć działanie.

#include <stdio.h>
#include <math.h>

void numberInput(double* a);
void numberSqrtResult(double a);

int main()
{
  double a;
  printf("Program służy do wypisywania pierwiastka kwadratowego podanej liczby rzeczywistej.\n");
  numberInput(&a);
  numberSqrtResult(a);
}

void numberInput(double* a){
  printf("podaj dodatnią liczbę rzeczywistą: \n");
  scanf("%lf", a);
  if(*a<0){
    printf("Podana liczba jest liczbą ujemną...");
  }
}

void numberSqrtResult(double a){
  double sqrtResult = sqrt(a);
  printf("Wynikiem pierwiastkowania kwadratowego liczby %.2lf jest: %lf\n", a, sqrtResult);
}