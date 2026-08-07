#include "header.h"

void scan_preprocessor(tok **head, tok **tail, FILE *fp, int *line_no)
{
    char buffer[100];

    int index = 0;

    char ch;

    buffer[index++] = '#';

    while ((ch = fgetc(fp)) != '\n' && ch != EOF)
    {
        if (ch != '\r')
        {
            buffer[index++] = ch;
        }
    }
    buffer[index] = '\0';

    add_token(head, tail, buffer, "PREPROCESSOR_DIRECTIVE", *line_no);

    if (ch == '\n')
    {
        (*line_no)++;
    }
}