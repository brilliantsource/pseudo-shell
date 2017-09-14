#include <stdio.h>
#include <string.h>

#define BUFFERSIZE 256
#define EXIT_OK    0

#define SHELL "shell"
#define EXIT  "exit"

// Pseudo-Shell Function
// Do nothing until the User writes EXIT
void f_vShell (char p_sPrompt[]) {
    char l_sCommand[BUFFERSIZE];

    while (1) {
        printf (p_sPrompt);
        fgets (l_sCommand, BUFFERSIZE, stdin);
        l_sCommand[strcspn (l_sCommand, "\n")] = '\0';
        if (0 == strcmp (l_sCommand, EXIT)) {
            break;
        } else {}
    }
}

// Main Function
// Assume that the command-line is /bin/sh -c other_params
// If the Argument equals SHELL, go to the f_vShell Function
// Otherwise print the last Argument
int main (int argc, char *argv[]) {
    // if 2 arguments, exit
    // if more arguments, launch the Pseudo-Shell function if the second argument is SHELL (the prompt is the last argument)
    // Otherwise, display the second argument
    if (argc > 2) {
        if (0 == strcmp (argv[2], SHELL)) {
            if (3 == argc) {
                f_vShell ("");
            } else {
                f_vShell (argv[argc-1]);
            }
        } else {
            printf ("%s\n", argv[argc-1]);
        }
    } else {}
    return EXIT_OK;
}