#include <stdio.h>
double cost(int Type, double Books, int Pages, int Sig) {

if (Type == 0){
    return ((Pages*7)+(((Pages/2)+(Sig-(Pages/2)%Sig))*Books*.01)+(Books*2))*1.175;
  } else {
    return ((Pages*28)+(((Pages/2)+(Sig-(Pages/2)%Sig))*Books*.04)+(Books*2))*1.175;
  }  
}

int main(void) {
  printf("Total cost of job = £%f\n", (cost(1,1000,32,16)+cost(0,2000,40,16)+cost(0,400,160,16)));
  printf("Total cost of job = £%f\n", (cost(1,50,30,16)));
  printf("Total cost of job = £%f\n", (cost(0,35,34,16)));
  printf("Total cost of job = £%f\n", (cost(0,35,34,8)));
  printf("Total cost of job = £%f\n", (cost(0,100,34,6)));
  return 0;
}
