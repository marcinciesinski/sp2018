struct point
{
  int x;
  int y;
};

struct rect{
  struct point low_left;
  struct point upp_right;
};

struct point make_point(int x, int y){
  struct point tmp;
  tmp.x = x;
  tmp.y = y;
  return tmp;
}
