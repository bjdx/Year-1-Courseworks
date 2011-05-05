#include <stdio.h>

double powerindian(double X, int Y) {

  if (Y==0) {
    return X = 1;
  } else {

    if (Y%2 == 0){
      return powerindian(X,(Y/2))*powerindian(X,(Y/2));
    
  } else {
      return X * (powerindian(X,Y-1));
  }
  }
}

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
  printf("1.0000000001 ^ 1000000000 = %f\n", powerindian(1.0000000001,1000000000));
  return 0;
}
