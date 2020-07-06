#include <stdio.h>

void foo(){
    printf("foo() was called\n");
}

// implicit declaration for functions
void boo();
int add(int a, int b);
double mean(int numbers[],int size);
void swap(int *px, int *py);

int main(int argc, const char* argv[]) {

  foo();
  boo();

  int result = add(10,5);
  printf("result: %d\n",result);


  int numbers[8] = {8,4,5,1,4,6,9,6};
  double ret_mean = mean(numbers,8);
  printf("mean: %.2f\n",ret_mean);

  int *x, *y;
  int a, b;

  a = 10;
  b = 5;

  // set value
  x = &a;
  y = &b;

  printf("value pointer x: %d \n",*x);
  printf("value pointer y: %d \n",*y);

  swap(x,y);
  printf("swap()\n");
  printf("value pointer x: %d \n",*x);
  printf("value pointer y: %d \n",*y);


  return 0;
}

void boo(){
    printf("boo() was called\n");
}

int add(int a, int b){
    return a + b;
}

double mean(int numbers[],int size){
    int i, total;
    double temp;

    for (i = 0; i < size; ++i){
        total += numbers[i];
    }

    temp = (double)total / (double)size;
    return temp;
}


void swap(int *px, int *py){
    int temp;

    // store pointer px value to temp
    temp = *px;
    // set pointer px by py value
    *px = *py;
    // set pointer py by temp value
    *py = temp;
}


