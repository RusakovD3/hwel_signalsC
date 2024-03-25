#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

#define PID_FILE "process.pid"

pid_t read_pid_from_file() {
    FILE *file = fopen(PID_FILE, "rb");
    if (file == NULL) {
        perror("Failed to open PID file for reading");
        exit(1);
    }
    pid_t pid;
    if (fread(&pid, sizeof(pid_t), 1, file) != 1) {
        perror("Failed to read PID");
        fclose(file);
        exit(1);
    }
    fclose(file);
    return pid;
}

int main() {
    pid_t pid = read_pid_from_file();
    printf("Sending SIGUSR1 to PID %d\n", pid);
    if (kill(pid, SIGUSR1) == -1) {
        perror("Failed to send SIGUSR1");
        exit(1);
    }
    return 0;
}
