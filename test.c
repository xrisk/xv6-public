#include "user.h"

int main(void) {
  int i;
  for (i = 0; i < 10; i++) {
    printf(1, "%d\n", i);
    sleep(100);
  }
  exit();
}
