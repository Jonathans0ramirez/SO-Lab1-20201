#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  for(int i = 1; i < argc; i++){
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    FILE *fp = fopen(argv[i], "r");
    if (fp == NULL) {
      printf("wcat: cannot open file %s\n", argv[i]);
      exit(1);
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        printf("%s", line);
    }
    printf("%s","\n------------------------------------\n");
  }
  exit(0);
}