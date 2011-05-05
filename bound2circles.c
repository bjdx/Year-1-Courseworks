#include <stdio.h>

/*circle and box were taken so I called the circles bob and the boxes tod.*/

typedef struct{ int x, y, r; } Circle;
typedef struct{ int xl, yl, xr, yr; } Box;

void prtBound(Box tod){
  printf("(%d,%d) (%d,%d)\n", tod.xl, tod.yl, tod.xr, tod.yr);
}

Box bound(Circle bob, Circle bob2){
  Box tod;
  Box tod2;

  tod.xl = bob.x - bob.r;
  tod.yl = bob.y - bob.r;
  tod.xr = bob.x + bob.r;
  tod.yr = bob.y + bob.r;

  tod2.xl = bob2.x - bob2.r;
  tod2.yl = bob2.y - bob2.r;
  tod2.xr = bob2.x + bob2.r;
  tod2.yr = bob2.y + bob2.r;

  if (tod.xl > tod2.xl) tod.xl = tod2.xl;
  if (tod.yl > tod2.yl) tod.yl = tod2.yl;
  if (tod.xr < tod2.xr) tod.xr = tod2.xr;
  if (tod.yr < tod2.yr) tod.yr = tod2.yr;

  printf("(%d,%d) (%d,%d)\n", tod.xl, tod.yl, tod.xr, tod.yr);
  return tod;
}

Circle create(Circle bob ) {
  Circle bob2;
  int temp[2];

  scanf("%d", temp);
  bob.x = temp[0];

  scanf("%d", temp);
  bob.y = temp[0];

  scanf("%d", temp);
  bob.r = temp[0];

  scanf("%d", temp);
  bob2.x = temp[0];

  scanf("%d", temp);
  bob2.y = temp[0];

  scanf("%d", temp);
  bob2.r = temp[0];

  bound(bob,bob2);
}


int main(void){
  Circle bob;
  create(bob);
  return 0;
}
