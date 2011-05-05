#include <stdio.h>

double power(unsigned int Y, double X) {
  int i = 1;
  double Z = X;

  for(i=1 ; Y != i ; i=i+1){
    X=X*Z;
  }
  return X;
}

int main(void) {
  printf("Interest = £%f\n",(1000*power(25,1.05)));
  return 0;
}
