#include <stdio.h> // Input and output- fgets, fclose, fopen.
#include <stdlib.h> // Exit.

#define LINE_SIZE 100 // 100 Characters.

FILE *r_file; // Defining FILE type pointer.
void print_file_content(char *file_name, int line_size) { // Process each filepath passed and display it's content.
    r_file = fopen(file_name, "r"); // Open file in Read mode.
    if (r_file == NULL) { // If file path doesn't exist -> exit.
        printf("wcat: cannot open file\n");
        exit(1); // Exit with code = 1.
    }

// Read line by line and print it.

    char content[line_size]; 
    while (fgets(content, line_size, r_file) != NULL) { // Print until eof is reached [params of fgets(char * type, size, FILE type pointer); 1 fgets outside loop ensure wcat not print previous buffer (last line) twice if passed with multiple files].
      printf("%s", content);
    }
    fclose(r_file); // Closing file.
}

int main(int argc, char *argv[]) { // argc: number of arguments including first argument as file name itself.
    if (!argc) {
      exit(1); // Exit with code = 1.
    }
    for (int i=1; i<argc; i++) {
      print_file_content(argv[i], LINE_SIZE);
    }
    return 0; // Exit if all files content displayed correctly or no file name passed with status code = 0.
}