#include "user.h"

int main(int argc, char *argv[]) {
  if (argc == 1) {
    printf(1, "usage: time <command>\n");
    return 1;
  }
  int pid;
  int start = uptime();

  switch (pid = fork()) {
  case -1:
    printf(1, "fork failed\n");
    return 1;
  case 0:
    exec(argv[1], argv + 1);
    exit();
  default:;
    int wtime, rtime;
    waitx(&wtime, &rtime);
    int end = uptime();
    printf(1, "\nw: %d r: %d a: %d\n", wtime, rtime, end - start);
    exit();
  }
  return -1;
}
