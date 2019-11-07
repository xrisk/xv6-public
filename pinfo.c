#include "proc.h"
#include "user.h"

int main(int argc, char **argv) {
  struct proc_stat st;
  if (argc != 2) {
    printf(1, "usage: pinfo [pid]\n");
    exit();
  }
  int pid = atoi(argv[1]);
  if (getpinfo(pid, &st) < 0) {
    printf(1, "syscall failed\n");
    exit();
  }
  printf(1, "pid: %d\n", st.pid);
  printf(1, "name: %s\n", st.name);
  printf(1, "runtime: %d\n", st.runtime);
  printf(1, "num_run: %d\n", st.num_run);
  printf(1, "current_queue: %d\n", st.current_queue);
#ifdef PRIORITY
  printf(1, "priority: %d\n", st.priority);
#endif
  exit();
}
