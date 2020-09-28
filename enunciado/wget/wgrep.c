#include <stdio.h> // Input and output- fgets, fclose, fopen.
#include <stdlib.h> // Exit.

void search_in_file(char *fname, char *str) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    FILE *file = fopen(fname, "r"); // Open file in read mode
    if (file == NULL) { // If file path doesn't exist -> exit.
        printf("wgrep: cannot open file\n");
        exit(1);
    }
    while ((read = getline(&line, &len, file)) != -1) { // While exists chars in the line read.
        if (strstr(line, str) != NULL) { // Check if line contains the word and print.
            printf("%s", line);
        }
    }
    fclose(file); // Closing file
}

int main(int argc, char *argv[]) {
    if(argc == 1 ) {
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }

    char *str = argv[1];
    if (argc == 2) {
        char buffer[500];
        while ( fgets(buffer, 500, stdin) ) {
            if (strstr(buffer, str) != NULL) {
                printf("%s", buffer);
            }
        }
    }

    for(int i=2; i<argc; i++) {
        search_in_file(argv[i],str);
    }

    return(0);
}