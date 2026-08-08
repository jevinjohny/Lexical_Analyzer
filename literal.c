#include "header.h"

void scan_char_constant(tok **head, tok **tail, FILE *fp, int *line_no)
{
    char buffer[4];

    int index = 0;

    buffer[index++] = '\'';

    char ch = fgetc(fp);

    if (ch == EOF || ch=='\n')
    {
        if (ch=='\n')
        {
            (*line_no)++;
        }
        buffer[index] = '\0';
        add_token(head, tail, buffer, "ERROR", *line_no);
        return;
    }

    if (ch != '\r')
    {
        buffer[index++] = ch;
    }

    ch = fgetc(fp);
    if (ch == '\'')
    {
        if (ch != '\r')
        {
            buffer[index++] = ch;
        }
        buffer[index] = '\0';
        add_token(head, tail, buffer, "CHAR_CONSTANT", *line_no);
    }
    else
    {
        buffer[index] = '\0';
        add_token(head, tail, buffer, "ERROR", *line_no);
    }
}

void scan_string_literal(tok **head, tok **tail, FILE *fp, int *line_no)
{
    char buffer[50];

    int index = 0;

    buffer[index++] = '"';

    char ch;
    while ((ch = fgetc(fp)) != '"' && ch != '\n' && ch != EOF)
    {
        if (ch != '\r')
        {
            buffer[index++] = ch;
        }
    }

    if (ch == '"')
    {
        buffer[index++] = ch;
        buffer[index] = '\0';
        add_token(head, tail, buffer, "STRING_LITERAL", *line_no);
    }
    else
    {
        buffer[index] = '\0';
        add_token(head, tail, buffer, "ERROR", *line_no);
        if (ch=='\n')
        {
            (*line_no)++;
        }
    }
}