#include <stdio.h>
double cost(int Type, double Books, int Pages) {

if (Type == 0){
    return ((Pages*7)+(((Pages/2)+(16-(Pages/2)%16))*Books*.01)+(Books*2))*1.175;
  } else {
    return ((Pages*28)+(((Pages/2)+(16-(Pages/2)%16))*Books*.04)+(Books*2))*1.175;
  }  
}

int main(void) {
  printf("Total cost of job = £%f\n", (cost(1,1000,32)+cost(0,2000,40)+cost(0,400,160)));
  printf("Total cost of job = £%f\n", (cost(1,50,30)));
  printf("Total cost of job = £%f\n", (cost(0,35,34)));
  return 0;
}
