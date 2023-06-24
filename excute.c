#include "shell.h"

/**
 *  execute :  function allows you to execute commands in your shell
 *  @commamd : argument has a right command
 * @arg : argumrnt has a array of user input after seprate it
 * 
 * return : status of process
*/

int execute(char *command, char **arg)
{
    if (strcmp(command, "cd") == 0) {
        return handle_cd_command(arg[1]);
        
    } else if (strcmp(command, "mv") == 0) {
        // Implement the 'mv' command functionality here
    } else if (strcmp(command, "cp") == 0) {
        // Implement the 'cp' command functionality here
    } else if (strcmp(command, "rm") == 0) {
        // Implement the 'rm' command functionality here
    } else {
        // Other commands not handled, execute as external command
        pid_t pid;
        int status;
        int num_args = 0;
        char **args;
        int i;

        /* Count the number of arguments */
        while (arg[num_args] != NULL && num_args < MAX_ARGS) {
            num_args++;
        }

        args = malloc((num_args + 1) * sizeof(char *));
        if (!args) {
            fprintf(stderr, "Error: failed to allocate memory\n");
            exit(EXIT_FAILURE);
        }

        /* Copy the command and arguments into the args array */
        args[0] = command;

        for (i = 1; i <= num_args; i++) {
            args[i] = arg[i];
        }
        args[num_args] = NULL;

        /* Fork a child process and execute the command */
        pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            /* Child process */
            status = execvp(args[0], args);
            if (status == -1) {
                perror(args[0]);
                /* exit(EXIT_FAILURE); */
            }
        } else {
            /* Parent process */
            if (waitpid(pid, &status, 0) == -1) {
                perror("waitpid");
                exit(EXIT_FAILURE);
            }
            if (WIFEXITED(status)) {
                return WEXITSTATUS(status); /* Return the exit status of the child process */
            } else {
                return 1;
            }
        }

        /* Free the dynamically allocated memory */
        free(args);
        return 1; /* Default return value in case no other return statement is reached */
    }
}

int handle_cd_command(char *arg)
{
    if (arg == NULL) {
        fprintf(stderr, "Error: missing directory argument for 'cd'\n");
        return 1;
    }

    int result = chdir(arg);
    if (result == -1) {
        perror("chdir");
        return 1;
    }

    return 0;
}
