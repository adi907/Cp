#include <stdio.h>

void main(){
  int sec,hh,mm,ss;
  printf("Input seconds:");
  scanf("%d", &sec);
  hh= sec/3600;
  mm= (sec-(hh*3600))/60;
  ss=(sec-(hh*3600)-(mm*60));
  printf("%d:%d:%d", hh,mm,ss);
  return 0;
}
