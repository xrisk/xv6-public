#include "proc.h"
#include "user.h"

int main(int argc, char **argv) {
  struct proc_stat st;
  if (argc != 2) {
    printf(1, "usage: test_pinfo [pid]\n");
    exit();
  }
  int pid = atoi(argv[1]);
  if (getpinfo(pid, &st) < 0) {
    printf(1, "syscall failed\n");
    exit();
  }
  printf(1, "pid: %d", st.pid);
  printf(1, " runtime: %d", st.runtime);
  printf(1, " num_run: %d", st.num_run);
  printf(1, " current_queue: %d", st.current_queue);
  printf(1, "\n");
  exit();
}
