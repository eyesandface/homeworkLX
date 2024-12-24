#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void executeCommand(const std::string& command)
{
    pid_t pid = fork();

    if (pid == 0)
    {
        if (command.find("silent") == 0)
        {
            std::string logFile = std::to_string(getpid()) + ".log";
            freopen(logFile.c_str(), "w", stdout);
            freopen(logFile.c_str(), "w", stderr);
        }

        system(command.c_str());
        exit(0);
    }

    else
        wait(NULL);
}

int main()
{
    std::string command;

    while (true)
    {
        std::cout << "Enter command: ";
        std::getline(std::cin, command);

        if (command == "exit")
        {
            std::cout << "Exiting.\n";
            break;
        }

        executeCommand(command);
    }
    return 0;
}
