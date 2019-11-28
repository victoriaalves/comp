#include <stdio.h>
#define SIZE 10
int x = 17894;
int b = 17894;
int a = 0;
long v1[SIZE] = {0,0,0,0,0,0,0,0,0,0};

int test( int a, int c );

int main( int x )
{
  for (x = 1; x < 10; x= x + 1)
    printf("hello \n");
  while(a < 10){
    printf("Testando 1,2,3\n");
    test(a, x);
    a = a + 1;
    break;
  }
}

int test( int a, int c ){
  v1[a] = 2;

  if (a < b)
  {
    printf("ola\n");
  }
  else
  {
    b = 1;
  }
}
