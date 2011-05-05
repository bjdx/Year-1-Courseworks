#include <stdio.h>

double power(int Y, double X) {
  if(Y==0){
    return X = 1;
  }

  if (Y < 0) {
    int i = -1;
    double Z = X;

    for(i=-1 ; Y != i ; i=i-1){
      X=X*Z;
    }

    return 1/X;

  } else {
    int i = 1;
    double Z = X;

    for(i=1 ; Y != i ; i=i+1){
      X=X*Z;
    }

    return X;
  }
}
int main(void) {
  printf("Interest = £%f\n",(1000*power(25,1.05)));
  printf("Put Away = £%f\n",(10000*power(-12,1.04)));
  return 0;
}
