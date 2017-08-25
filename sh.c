#include <stdio.h>
#include <string.h>

#define BUFFERSIZE 256
#define EXIT_OK    0

#define SHELL "shell"
#define EXIT  "exit"

// Pseudo-Shell Function
// Do nothing until the User writes EXIT
void f_vShell (char p_sPrompt[])
{
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
// If the Argument equals SHELL, go to the f_vShell Function
// Otherwise print the last Argument
int main (int argc, char *argv[])
{
    // if one Argument, exit
    // if two Arguments, launch the Pseudo-Shell Function if the Value is the Keyword
    // if more Arguments, launch the Pseudo-Shell Function if the Value is the Keyword and take the last Argument as the Prompt
    //                    display the last Argument
    if (argc > 1) {
        if (0 == strcmp (argv[1], SHELL)) {
            if (2 == argc) {
                f_vShell ("");
            } else {
                f_vShell (argv[argc-1]);
            }
        } else {
            printf ("%s\n", argv[1]);
        }
    } else {}
    return EXIT_OK;
}