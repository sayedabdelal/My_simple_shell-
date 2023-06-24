#include "shell.h"

/**
 * envi - search  searching for the executable file
 * @args - given command in the directories specified in the PATH environment variable.
 * return - 
*/
char* envi(char *args)
{   
    char* path_copy, *env_list = NULL, *cmd, *path;
    char* delium = ":";
    int command_length, token_length;
    struct stat buffer;

    if (args == NULL) {
        return NULL;
    }
    else if (strcmp(args, "exit") == 0) {
        /* Exit command*/
        exit(EXIT_SUCCESS);
    }
        /* Get the PATH environment variable*/
        path = getenv("PATH");
        if (path == NULL || strlen(path) == 0) {
            printf("PATH environment variable not found\n");
            return NULL;
        }
        /* Construct the command string*/
        command_length = strlen(args);
        path_copy = strdup(path);

        cmd = strtok(path_copy,delium);
        while(cmd != NULL)
        {
            token_length = strlen(cmd);
            env_list = malloc(token_length + command_length + 2);
            env_list[0] = '\0';
            
            strcat(env_list,cmd);
            strcat(env_list,"/");
            strcat(env_list, args);

            /* check if file found or not in system 0 >> sucess -1 >> error*/
            if (stat (env_list, &buffer) == 0)
            {
                
                free(path_copy);
                /*free(env_list);*/
                return(env_list);
            } else 
            {
                // printf("check path: %s\n", env_list);
                free(env_list);
                /* check anther command in path files*/
                cmd = strtok(NULL, delium);
            }
        }
        free(path_copy);
        /* user give me path direct*/
        if (stat (args, &buffer) == 0)
        {
            return args;
        }
        /* Command not found*/
        return NULL;

}