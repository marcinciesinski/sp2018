// FizzBuzz is a children's game where
// you count from 1 to 100. Easy, right?

// Here's the catch: instead of saying
// numbers divisible by 3, say "Fizz".
// And instead of saying numbers
// divisible by 5, say "Buzz". For
// numbers divisible by both 3 and 5, say
// "FizzBuzz".

// "1, 2, Fizz, 4, Buzz"...and so forth

#include <stdio.h>

int main()
{
  for (int i = 1; i <= 100; i++)
  {
    if (i % 3 == 0 && i % 5 == 0)
      printf("FizzBuzz\n");
    else if (i % 3 == 0)
      printf("Fizz\n");
    else if (i % 5 == 0)
      printf("Buzz\n");
    else
      printf("%d\n", i);
  }
}
