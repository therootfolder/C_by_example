#include <stdio.h>

int main(int argc, const char* argv[]) {

  int n;
  n = 10;

  printf("value n: %d \n",n);
  printf("address n: %x \n",(unsigned int)&n);

  return 0;
}