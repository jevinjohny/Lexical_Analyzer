#include "header.h"

int skip_comment(FILE *fp, int *line_no)
{
    char next = fgetc(fp);

    if (next == '/')
    {
        char ch;
        while ((ch = fgetc(fp)) != '\n' && ch != EOF)
            ;
        (*line_no)++;
        return 1;
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
        return 1;
    }
    ungetc(next,fp);
    return 0;
}