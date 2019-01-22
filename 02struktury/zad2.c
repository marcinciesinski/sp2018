// 2. Napisać funkcję disjointrect sprawdzającą,
//  czy prostokąty są rozłączne:

// /* disjointrect: zwróć 1 jeśli r1 jest rozłączny z r2,
//    0 — w przeciwnym przypadku */
// int disjointrect(struct rect r1, struct rect r2);

#include <stdio.h>
#include "strctcreate.h"

int disjointrect(struct rect r1, struct rect r2);

int main()
{
  struct rect r1 = {
      .low_left = make_point(3, 2),
      .upp_right = make_point(5, 8)};

  struct rect r2 = {
      .low_left = make_point(6, 3),
      .upp_right = make_point(15, 10)};

  printf("%d\n", disjointrect(r1, r2));
}

int disjointrect(struct rect r1, struct rect r2)
{
  return r1.upp_right.x <= r2.low_left.x || r1.upp_right.y <= r2.low_left.y 
    || r1.low_left.x >= r2.upp_right.x || r1.low_left.y >= r2.upp_right.y;
}
