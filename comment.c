#include "header.h"

void skip_comment(FILE *fp)
{
    char next = fgetc(fp);

    if (next == '/')
    {
        char ch;
        while ((ch = fgetc(fp)) != '\n' && ch != EOF)
            ;
    }
    else if (next == '*')
    {
        char ch;
        char prev=0;
        
        while (((ch = fgetc(fp)) != EOF ))
        {
            if ( ch == '/' && prev=='*')
            {
                break;
            }
            prev=ch;
        }
    }
}