#include "shell.h"

/**
 * parse_line - Parses a line of input into individual arguments.
 * @line: The input line to parse.
 * @line_copy: A copy of the input line that gets modified during parsing.
 *
 * Return: An array of strings containing the parsed arguments.
 */

char **parse_line(char *line, char **line_copy)
{
    char **args;
    const char *delim = " \t\n";
    char *token;
    int num_t = 0, i;


    token = strtok(line, delim);
    while (token!= NULL) {
        num_t++;
        token = strtok(NULL, delim);
        
    }
    if (num_t > MAX_ARGS) {
        fprintf(stderr, "Error: too many arguments\n");
        return NULL;
    }
    printf("num >>> token >> %d\n", num_t);


    
    args = malloc((num_t + 1) * sizeof(char *));
    if (!args) 
    {
        fprintf(stderr, "Error: failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(*line_copy, delim);
    i = 0;

    while (token!= NULL && i < num_t) {
        args[i++] = token;
        token = strtok(NULL, delim);
    }

    args[i] = NULL; 

    return args;
}

/**
 *  EXIT_FAILURE >> constant defined in the <stdlib.h> header file
 *       unsuccessful termination of a program, defined as a non-zero integer value (usually 1)
 * exit(EXIT_FAILURE) is used to 
 *      terminate the program if there is an error during the execution,
*/

/* DIFFERENT exit(EXIT_FAILURE) , return 1*/
/*
exit(EXIT_FAILURE): 
    return control to the operating system
    allow program to know determine the exit status of the program.
*/
/*
return 1
these used inside a funtion to return a error condition 
///However, it does not terminate the entire program like exit() does. 
*/

/* diffrent : 
If you use return 1 inside a function, the program will continue executing 
unless the function is the *****main****** function
, in which case it will exit when the main function returns. == exit()
*/