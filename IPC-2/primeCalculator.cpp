#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int find_prime(int m) {
    int count = 0;
    int num = 2;
    while (count < m) {
        if (is_prime(num)) {
            count++;
        }
        num++;
    }
    return num - 1;
}

int main() {
    int pipe_parent_to_child[2], pipe_child_to_parent[2];
    if (pipe(pipe_parent_to_child) == -1 || pipe(pipe_child_to_parent) == -1) {
        std::cerr << "Pipe creation failed!" << std::endl;
        return 1;
    }

    pid_t pid = fork();
    if (pid == -1) {
        std::cerr << "Fork failed!" << std::endl;
        return 1;
    }

    if (pid > 0) {
        close(pipe_parent_to_child[0]);
        close(pipe_child_to_parent[1]);

        while (true) {
            std::cout << "[Parent] Please enter the number: ";
            int m;
            std::cin >> m;

            if (m == -1) {  
                break;
            }

            std::cout << "[Parent] Sending " << m << " to the child process..." << std::endl;
            write(pipe_parent_to_child[1], &m, sizeof(m));  

            std::cout << "[Parent] Waiting for the response from the child process..." << std::endl;

            int result;
            read(pipe_child_to_parent[0], &result, sizeof(result));  
            std::cout << "[Parent] Received calculation result of prime(" << m << ") = " << result << "..." << std::endl;
        }

        close(pipe_parent_to_child[1]);
        close(pipe_child_to_parent[0]);
        wait(nullptr);

    } else {
        close(pipe_parent_to_child[1]);
        close(pipe_child_to_parent[0]);

        while (true) {
            int m;
            read(pipe_parent_to_child[0], &m, sizeof(m));

            if (m == -1) {
                break;
            }

            std::cout << "[Child] Calculating " << m << "-th prime number..." << std::endl;

            int prime_result = find_prime(m);

            std::cout << "[Child] Sending calculation result of prime(" << m << ")..." << std::endl;
            write(pipe_child_to_parent[1], &prime_result, sizeof(prime_result));
        }

        close(pipe_parent_to_child[0]);
        close(pipe_child_to_parent[1]);
        exit(0);
    }

    return 0;
}
