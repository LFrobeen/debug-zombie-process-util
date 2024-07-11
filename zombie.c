#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
    if (argc < 2) {
        while (1) {
            spawn_zombie();
            sleep(1);
        }

        return 0;
    }

    if (argc >= 2) {
        int number = atoi(argv[1]);

        printf("Spawning %d zombies\n", number);
        for ( ; number > 0; number -= 1 ) {
            spawn_zombie();
        }
    }

    if (argc >= 3) {
        int number = atoi(argv[2]);
        printf("Sleep %d\n", number);
        sleep(number);
    }

    return 0;
}

void spawn_zombie() {
    pid_t child_pid = fork();

    if (child_pid == 0) {
        // Create sub-zombie
        pid_t child_pid = fork ();

        // Exit immediately
        exit (0);
    } else {
        printf("Started new process %d\n", child_pid);
    }
}
