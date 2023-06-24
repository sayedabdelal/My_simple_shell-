#include "shell.h"


int main (int argc, char *argv[])
{
    char **aliases = NULL;
    int num_t;
    (void)argv; /* Mark the argv parameter as unused to suppress the warning*/
    /* Set up signal handlers*/
    signal(SIGINT, handle_signal);
    signal(SIGQUIT, handle_signal);
    num_t = argc;
    /* Run the shell loop*/
    return shell_loop(num_t);
}
void handle_signal(int signal)
{
    if (signal == SIGINT) {
        printf("Received SIGINT signal\n");
        exit(EXIT_SUCCESS);
    } else if (signal == SIGQUIT) {
        printf("Received SIGQUIT signal\n");
        exit(EXIT_SUCCESS);
    }
}










/*Compilation
Your shell will be compiled this way:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
*/


/*(WIFEXITED(status)
    macro is used to check if the child process exited normally. 
    
    normally exit >> return >> 0 >> sucess exit
    overwise >> return 1 >> not sucess


*/

/* Update the flag variable based on the command execution*/
        /*int should_continue = 1;
         should_continue = (status == 0); */
        /* expression that compares the value of status with 0.
        if status (0) true >> loop 1
        else >> 0 loop >> exit.
        */
