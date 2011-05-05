#include <stdio.h>
typedef struct{ int x1, y1, x2, y2;} Line;
typedef struct{ int x, y, r; } Circle;
typedef struct{ int xl, yl, xr, yr; } Box;

Line GLine;
Circle GCircle;
Box GBox;
int Check = 0;
char c[100];
int i = 0;

int addCircle(void){
  i = i+2;
  GCircle.x = (c[i]-48);
  i = i+2;
  GCircle.y = (c[i]-48);
  i = i+2;
  GCircle.r = (c[i]-48);

  if (Check == 0) {
    GBox.xl = (GCircle.x - GCircle.r);
    GBox.xr = (GCircle.x + GCircle.r);
    GBox.yl = (GCircle.y - GCircle.r);
    GBox.yr = (GCircle.y + GCircle.r);
    Check = 1;
  }
  
  if (Check == 1){
    if ((GCircle.x - GCircle.r) < GBox.xl) GBox.xl = (GCircle.x - GCircle.r);
    if ((GCircle.x + GCircle.r) > GBox.xr) GBox.xr = (GCircle.x + GCircle.r);
    if ((GCircle.y - GCircle.r) < GBox.yl) GBox.yl = (GCircle.y - GCircle.r);
    if ((GCircle.y + GCircle.r) > GBox.yr) GBox.yr = (GCircle.y + GCircle.r);
  }
  i=i+2;
}

int addLine(void){
  i = i+2;
  GLine.x1 = (c[i] - 48);
  i = i+2;
  GLine.y1 = (c[i] - 48);
  i = i+2;
  GLine.x2 = (c[i] - 48);
  i = i+2;
  GLine.y2 = (c[i] - 48);

  if (Check == 0){
    printf("(%d,%d)\n", GLine.x1, GLine.x2);    
    if (GLine.x1 < GLine.x2){
      GBox.xl = GLine.x1;
      GBox.xr = GLine.x2;
    }else{
      GBox.xr = GLine.x1;
      GBox.xl = GLine.x2;      
    }
    if (GLine.y1 < GLine.y2){
      GBox.yl = GLine.y1;
      GBox.yr = GLine.y2;
    }else{
      GBox.yr = GLine.y1;
      GBox.yl = GLine.y2;       
    }
    Check = 1;
  }

  if (Check == 1){
    if (GLine.x1 < GLine.x2){
      if(GLine.x1 < GBox.xl) GBox.xl = GLine.x1;
      if(GLine.x2 > GBox.xr) GBox.xr = GLine.x2;
    }else{
      if(GLine.x2 < GBox.xl) GBox.xl = GLine.x2;
      if(GLine.x1 > GBox.xr) GBox.xr = GLine.x1;      
    }
    if (GLine.y1 < GLine.y2){
      if(GLine.y1 < GBox.yl) GBox.yl = GLine.y1;
      if(GLine.y2 > GBox.yr) GBox.yr = GLine.y2;
    }else{
      if(GLine.y2 < GBox.yl) GBox.yl = GLine.y2;
      if(GLine.y1 > GBox.yr) GBox.yr = GLine.y1;
    }
  }
  i = i+2;
}

int main(void){
  scanf("%99[0-9clCL ]", c );
  while (c[i] == 'C' || c[i] == 'L'){
    if (c[i]=='C') {
      addCircle();
    }else{
      addLine();
    }
  }
  printf("(%d,%d) (%d,%d)\n", GBox.xl, GBox.yl, GBox.xr, GBox.yr);
  return 0;
}
