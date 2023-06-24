#include "shell.h"

/**
 * shell_loop - Executes the main loop of the shell, where it prompts for user input,
 *           parses the input.
 * 
 * return : EXIT_SUCCESS(0) futcion is sucess
*/

/*
 * EXIT_SUCCESS is a constant defined in the stdlib.h header file in C
 * The value of EXIT_SUCCESS is typically 0
*/


int shell_loop(int num_t)
{
    char *line = NULL;
    char **args = NULL;
    int status;
    int nchars_read;
    char* command = NULL;
    size_t line_size = 0;
    char *line_copy;
    int i;
    (void)num_t; /* Mark the num_t parameter as unused to suppress the warning*/


    do {
        /*Print the prompt*/
        printf("$ ");

        /*Read a line from stdin*/
        nchars_read = getline(&line, &line_size, stdin);
        if (nchars_read  == -1) {
            perror("getline");
            exit(EXIT_FAILURE);
        }
        /* make a copy of the command that was typed */
        line_copy = strdup(line);
        /* Parse the line into arguments*/
        args = parse_line(line, &line_copy);

        for (i = 0; args[i]!= NULL; i++)
        {
            printf("%s\n", args[i]);
        }
        
        /* Execute the command*/
        
        command = envi(args[0]);
        if (command!= NULL) {
            status = execute(command, args); /*0 >> sucess , NOT 0 >> error*/
            free(command);  
            if (status != 0) {
                printf("Error: Command execution failed\n");
            } 
        } else if (command == NULL){
            if (args[0] == NULL)
            {
                printf("Error: Command not found: %s\n", args[0]);
            } else 
            {
                printf("Error: Command is error: %s\n", args[0]);
            }
            /* status = 1; to contune loop*/
        }
        status = 1; /* updata status after excute*/

        /* Free memory*/
        if (args) {
            free(args);
        } else {
            free(line);
            if (line_copy)
            {
                /* line_copy are still not NULL*/
                free(line_copy);
            }
        }
        

    } while (status);

    return EXIT_SUCCESS;
}
