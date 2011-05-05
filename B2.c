/* bd0906     Barney    VERSION B */


#include <stdio.h>

double ninrow( int n, double H ) {
  int i=0 ;
  double p = 1.0 ;
  while( i<n ) {
    p = p * H ;
    i++ ;
  }
  return p ;
}

int main() {
  int i=0 ;

  while (i<10) {
     if (ninrow(i,0.5)<0.1) {
      i = i + 1;
      } else {
      printf( "The probability of heads %d times in a row is %f\n", i, ninrow(i, 0.5) ) ;
    i = i+1;
    }
  }
  return 0 ;
}
