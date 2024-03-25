#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

#define PID_FILE "process.pid"

void write_pid_to_file() {
    FILE *file = fopen(PID_FILE, "wb");
    if (file == NULL) {
        perror("Failed to open PID file for writing");
        exit(1);
    }
    pid_t pid = getpid();
    fwrite(&pid, sizeof(pid_t), 1, file);
    fclose(file);
}

int main() {
    write_pid_to_file();
    printf("PID written to %s\n", PID_FILE);

    sigset_t waitset;
    int sig;
    int result;

    sigemptyset(&waitset);
    sigaddset(&waitset, SIGUSR1);
    result = sigprocmask(SIG_BLOCK, &waitset, NULL);
    if (result == -1) {
        perror("sigprocmask");
        exit(1);
    }

    printf("Waiting for SIGUSR1...\n");
    while (1) {
        if (sigwait(&waitset, &sig) == 0) {
            printf("Received SIGUSR1 signal.\n");
        } else {
            perror("sigwait");
            exit(1);
        }
    }
    
    return 0;
}
