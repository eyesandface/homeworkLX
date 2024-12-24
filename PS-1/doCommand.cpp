#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <ctime>

void do_command(char** argv)
{
   time_t start = time(nullptr);

   if(pid_t pid = fork(); pid == 0)
   {
      execvp(argv[0], argv);
      perror("execvp");
      exit(EXIT_FAILURE);
   }

   else if(pid > 0)
   {
      int status;
      waitpid(pid, &status, 0);

      time_t end = time(nullptr);

      std::cout << "Exit code: " << WEXITSTATUS(status) << ". Time: " 
                << difftime(end, start) << " seconds." << std::endl;
   }

   else
   {
      perror("fork");
   }
}




int main(int argc, char* argv[])
{
   if(argc < 2)
   {
      std::cerr << "Usage: ./do-commanr <command> [args...]" << std::endl;
      return EXIT_FAILURE;
   }

   do_command(argv+1);
   return 0;
}
