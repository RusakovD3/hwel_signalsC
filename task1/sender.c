#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main() {
    pid_t pid;
    
    printf("Enter the PID of the process to send SIGUSR1: ");
    if (scanf("%d", &pid) == 1){
            if (kill(pid, SIGUSR1) == -1) {
            perror("Error sending SIGUSR1");
            return 1;
        }
        
        printf("SIGUSR1 signal sent successfully to process %d\n", pid);
    } else {
        perror("pid input");
    }
    
    return 0;
}
