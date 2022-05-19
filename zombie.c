#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main ()
{
  
  while (1) {
    printf("Starting new process...\n");
    
    pid_t child_pid;child_pid = fork ();
    
    if (child_pid == 0) {
      break; 
    }
    
    sleep(1);
  }
  
  exit (0);
  
  return 0;
}
