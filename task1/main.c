#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void signal_handler(int signal) {
    if (signal == SIGUSR1) {
        printf("Received SIGUSR1 signal from user 1!\n");
    }
}

int main() {
    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    printf("Waiting for SIGUSR1...\n");
    while (1) {
        sleep(1);
    }

    return 0;
}
