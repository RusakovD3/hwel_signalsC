#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main() {
    pid_t pid;

    printf("Enter the PID of the process to send SIGTERM: ");
    scanf("%d", &pid);

    if (kill(pid, SIGTERM) == -1) {
        perror("Error sending SIGINT");
        return 1;
    }

    printf("SIGINT signal sent successfully to process %d\n", pid);

    return 0;
}
