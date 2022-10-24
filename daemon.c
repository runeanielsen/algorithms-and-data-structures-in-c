#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
  FILE *fp = NULL;
  pid_t process_id = 0;
  pid_t sid = 0;

  // Create child process
  process_id = fork();
  if (process_id < 0) {
    printf("fork failed!\n");
    exit(1);
  }

  // Parent process, should be killed on successful fork.
  if (process_id > 0) {
    printf("process_id of child process %d\n", process_id);
    _exit(0);
  }

  // Clean file mask
  umask(0);

  // Set new session
  sid = setsid();
  if (sid < 0) {
    exit(1);
  }

  // Change the current working directory to root
  chdir("/");

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  fp = fopen("/tmp/daemon_example.txt", "w+");

  // Dont block context switches, let the process sleep for some time.
  while (1) {
    sleep(1);
    fprintf(fp, "Logging info...\n");
    fflush(fp);
  }

  fclose(fp);

  return EXIT_SUCCESS;
}
