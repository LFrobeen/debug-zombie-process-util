#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main ()
{
  while (1) {
    printf("Starting new process...\n");
    
    // Spawns a zombie spawner
    pid_t child_pid = fork ();
    
    if (child_pid == 0) {
      pid_t child_pid = fork ();
      exit (0);
      return 0;
    }
    
    sleep(10);
  }
  
  exit (0);
  return 0;
}
