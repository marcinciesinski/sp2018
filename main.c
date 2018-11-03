#include <stdio.h>

void wczytajDane(int* a, int* b);
void wypiszWyniki(int k, int m);

int main()
{
  int x, y;
  wczytajDane(&x, &y);
  wypiszWyniki(x, y);
}

void wczytajDane(int* a, int* b){
  printf("podaj a, b: ");
  scanf("%d %d", a, b);
}

void wypiszWyniki(int k, int m){
  printf ("Wyniki czterech działań na x = %d, y = %d\n", k, m);
  printf ("x + y = %d\n", k+m);
}