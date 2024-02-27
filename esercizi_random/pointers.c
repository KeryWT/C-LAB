#include <stddef.h>
#include <stdio.h>

int main(void) {
  int age = 30;
  int *pAge = NULL;
  pAge = &age;

  printf("Address of age: %p USING AGE\n", (void *)&age);
  printf("Value of age: %d USING AGE\n", age);
  printf("Address of age: %p USING pAge\n", (void *)pAge);
  printf("Value of age: %d USING pAge\n", *pAge);
}
