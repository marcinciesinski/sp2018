// Napisz program, który wypisuje kolejne potęgi
// liczby 2 nie przekraczające 2010.

#include <stdio.h>
#include <math.h>

void powerOfTwo();

int main()
{
  printf("Program wypisuje kolejne potęgi liczby 2, nie przekraczając liczby 2010:\n");
  powerOfTwo();
}
void powerOfTwo()
{
  int power = 0;
  int result = 0;
  while (result < 2010)
  {
    result = pow(2, power);
    if (result > 2010)
      break;
<<<<<<< HEAD
    printf("\t2^%2d = %5d\n", power, result);
=======
    printf("2^%d = %4d \n", power, result);
>>>>>>> 2c89fddea958bed23cd9a376b245a5915be79b44
    power++;
  }
}
