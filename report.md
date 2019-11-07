# Report

The benchmark program is as follows:

```c
#include "user.h"

int main(void) {
  int i;
  for (i = 0; i < 55; i++) {
    int r = fork();
    if (r == -1) {
      printf(2, "failed to fork!\n");
      exit();
    } else if (r == 0) {
      volatile int var, j, z;
      for (z = 0; z < 2; z++) {
        for (j = 0; j < 10000000; j++) {
          var = (var + j * j) % 10000007;
        }
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
```


The different scheduling methods used were:

## total run time

Round Robin:

1. 1864 ticks
2. 1685 ticks
3. 1804 ticks

PBS:

1. 1872 ticks
2. 1970 ticks
3. 1785 ticks

FCFS:

1. 1852 ticks
2. 1689 ticks
3. 1930 ticks

MLFQ:

1. 1813 ticks
2. 1668 ticks
3. 1748 ticks

## average wait time

round robin: 1426
FCFS: 834
MLFQ: 1299
PBS: 792

