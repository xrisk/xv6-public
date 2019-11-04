#include "user.h"

int main(int argc, char *argv[]) {
  if (argc == 1) {
    printf(1, "usage: time <command>\n");
    return 1;
  }
  int pid;

  switch (pid = fork()) {
  case -1:
    printf(1, "fork failed\n");
    return 1;
  case 0:
    exec(argv[1], argv + 1);
    exit();
  default:;
    int rtime, wtime;
    if (waitx(&wtime, &rtime) == -1) {
      printf(1, "no children running\n");
      return 1;
    }
    printf(1, "runtime: %d wait-time: %d\n", rtime, wtime);
    exit();
  }
  return -1;
}
