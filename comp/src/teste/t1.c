#include <stdio.h>

int varg = 17;

int func2() {
  printf("ola\n");
}

int main() {
  varg = varg + 3;
  printf("var: %d\n", varg);
  func2();
}
