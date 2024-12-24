#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstring>
#include <pwd.h>

void signal_handler(int signum, siginfo_t* info, void* context) {
    pid_t sender_pid = info->si_pid;
    uid_t sender_uid = info->si_uid;
    
    struct passwd *pw = getpwuid(sender_uid);
    const char *sender_user = (pw != nullptr) ? pw->pw_name : "unknown";
    
    std::cout << "Received a SIGUSR1 signal from process " << sender_pid
              << " executed by " << sender_uid << " (" << sender_user << ").\n";

    std::cout << "State of the context: EIP = [unavailable], EAX = [unavailable], EBX = [unavailable].\n";
}

int main() 
{
    std::cout << "Process PID: " << getpid() << std::endl;

    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO; 
    sa.sa_sigaction = signal_handler;
    sigemptyset(&sa.sa_mask);
    
    if (sigaction(SIGUSR1, &sa, nullptr) == -1) {
        perror("Error setting up signal handler");
        return 1;
    }

    while (true) {
        sleep(10);
    }

    return 0;
}
