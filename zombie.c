#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main ()
{
  while (1) {
    printf("Starting new process...\n");
    
    pid_t child_pid = fork ();
    
    if (child_pid == 0) {
      exit (0);
      return 0;
    }
    
    sleep(10);
  }
  
  exit (0);
  return 0;
}
