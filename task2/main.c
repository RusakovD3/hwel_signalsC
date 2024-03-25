#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int sig) {
    printf("Received SIGINT signal. Continuing execution...\n");
}

int main() {
    printf("PID of this process: %d\n", getpid());

    struct sigaction sa;
    sa.sa_handler = sigint_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("Failed to set SIGINT handler");
        return 1;
    }

    while (1) {
        sleep(1);
    }

    return 0;
}
