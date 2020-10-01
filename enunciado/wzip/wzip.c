#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void compresFile(char *fileName, char *oldChar, int *characterRep)
{
	FILE *file = fopen(fileName, "r");
	if (file == NULL)
	{
		printf("wgrep: cannot open file\n");
		exit(1);
	}
	char actChar = fgetc(file);

	if (oldChar == 0)
	{
		*oldChar = actChar;
		characterRep = 0;
	}

	do
	{
		if (*oldChar != actChar)
		{
			fwrite(characterRep, 4, 1, stdout);
			printf("%c", *oldChar);
			*characterRep = 1;
			*oldChar = actChar;
		}
		else
		{
			(characterRep)++;
		}
	} while ((actChar = fgetc(file)) != EOF);
	fclose(file);
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("%s", "wzip: file1 [file2 ...]\n");
		exit(1);
	}

	char oldChar;
	int characterRep;

	for (int i = 1; i < argc; i++)
	{
		compresFile(argv[i], &oldChar, &characterRep);
	}
	fwrite(&characterRep, 4, 1, stdout);
	printf("%c", oldChar);
	return (0);
}