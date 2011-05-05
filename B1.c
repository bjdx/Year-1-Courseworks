/* bd0906     Barney    VERSION B */
#include <stdio.h>


int trafficfine( int speed, int maxspeed ) {

  if( speed > maxspeed+20 ) {
    return 160 ;
  }
  if( speed > maxspeed+10 ) {
    return 80 ;
  }
  if( speed > maxspeed ) {
    return 40 ;
  }
  return 0 ;
}

int main() {
  printf( "Fine for speeding at 100: %d\n", trafficfine(100 , 60));
  printf( "Fine for speeding at 75: %d\n", trafficfine(75 , 60));
  printf( "Fine for speeding at 30: %d\n", trafficfine(30 ,60));
  printf( "Fine for speeding at 60 in 30 zone: %d\n", trafficfine(60,30));
  return 0 ;
}
