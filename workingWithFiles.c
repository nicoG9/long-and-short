#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Must supply an input file and two output files as parameters.\n");
        exit(1);
    }
    
    FILE *in = fopen(argv[1], "r");
    FILE *out1 = fopen(argv[2], "w");
    FILE *out2 = fopen(argv[3], "w");
    if (!in || !out1 || !out2)
    {
        printf("Can't open one or more files for reading!\n");
        exit(1);
    }
    char line[255];
    int length, file1Hits, file2Hits;
    FILE *destFile;
    while (fgets(line, 255, in) != NULL)
    {
        length = strlen(line);
        //printf("Length of line: %d\n", length);
        if (length < 21)
        {
            destFile = out1;
            file1Hits += 1;
            for (int i = 0; i < length; i++)
            {
                line[i] = toupper(line[i]);
            }
        }
        else
        {
            destFile = out2;
            file2Hits += 1;
            for (int i = 0; i < length; i++)
            {
                line[i] = tolower(line[i]);
            }
        }
        fprintf(destFile, "%s", line);
    }

    printf("%d lines written to %s\n%d lines written to %s\n", file1Hits, argv[2], file2Hits, argv[3]);
    fclose(in);
    fclose(out1);
    fclose(out2);
}