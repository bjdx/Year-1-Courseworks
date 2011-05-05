#include <stdio.h>


typedef struct{ int x, y, r; } Circle;
typedef struct{ int xl, yl, xr, yr; } Box;

void prtBound(Box tod){
  printf("(%d,%d) (%d,%d)\n", tod.xl, tod.yl, tod.xr, tod.yr);
}

Box bound(Circle bob){
  Box tod;
  tod.xl = bob.x - bob.r;
  tod.yl = bob.y - bob.r;
  tod.xr = bob.x + bob.r;
  tod.yr = bob.y + bob.r;
  printf("(%d,%d) (%d,%d)\n", tod.xl, tod.yl, tod.xr, tod.yr);
  return tod;
}

Circle create(int x,int y,int r) {
  Circle bob;
  bob.x = x;
  bob.y = y;
  bob.r = r;
  printf( "Your Circle: \nCentre = (%d,%d)\n", bob.x ,bob.y );
  printf( "Radius = %d\n", bob.r );
  bound(bob);
}


int main(void){
  create(1,2,3);
  return 0;
}
