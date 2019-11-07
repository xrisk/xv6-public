#include "user.h"

int main(void) {
  int i;
  for (i = 0; i < 55; i++) {
    int r = fork();
    if (r == -1) {
      printf(2, "failed to fork!\n");
      exit();
    } else if (r == 0) {
      volatile int var, j;
      for (j = 0; j < 10000000; j++) {
        var = (var + j * j) % 10000007;
      }
      exit();
    }
  }
  for (i = 0; i < 55; i++) {
    int wtime, rtime;
    int pid = waitx(&wtime, &rtime);
    printf(1, "%d: w %d r %d\n", pid, wtime, rtime);
  }
  exit();
}
