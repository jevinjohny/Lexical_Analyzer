#include "header.h"

void skip_comment(FILE *fp, int *line_no)
{
    char next = fgetc(fp);

    if (next == '/')
    {
        char ch;
        while ((ch = fgetc(fp)) != '\n' && ch != EOF)
            ;
        (*line_no)++;
    }
    else if (next == '*')
    {
        char ch;
        char prev = 0;

        while (((ch = fgetc(fp)) != EOF))
        {
            if (ch == '/' && prev == '*')
            {
                break;
            }
            else if (ch == '\n')
            {
                (*line_no)++;
            }
            prev = ch;
        }
    }
}