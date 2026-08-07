#include "header.h"
int scan_operator(tok **head, tok **tail, FILE *fp, char first_chara)
{
    char buffer[3]; // max 2 character operator

    buffer[0] = first_chara;

    buffer[1] = '\0';
    buffer[2] = '\0';

    char next = fgetc(fp);

    switch (first_chara)
    {
    case '=':
    {
        if (next == '=')
        {
            buffer[1] = '=';
        }
        else
        {
            ungetc(next, fp);
        }
        break;
    }
    case '>':
    {
        if (next == '=')
        {
            buffer[1] = '=';
        }
        else
        {
            ungetc(next, fp);
        }
        break;
    }
    case '<':
    {
        if (next == '=')
        {
            buffer[1] = '=';
        }
        else
        {
            ungetc(next, fp);
        }
        break;
    }
    case '!':
    {
        if (next == '=')
        {
            buffer[1] = '=';
        }
        else
        {
            ungetc(next, fp);
        }
        break;
    }
    case '+':
    {
        if (next == '+')
        {
            buffer[1] = '+';
        }
        else
        {
            ungetc(next, fp);
        }
        break;
    }
    case '-':
    {
        if (next == '-')
        {
            buffer[1] = '-';
        }
        else
        {
            ungetc(next, fp);
        }
        break;
    }
    case '&':
    {
        if (next == '&')
        {
            buffer[1] = '&';
        }
        else
        {
            ungetc(next, fp);
        }
        break;
    }
    case '|':
    {
        if (next == '|')
        {
            buffer[1] = '|';
        }
        else
        {
            ungetc(next, fp);
        }
        break;
    }
    default:
    {
        ungetc(next, fp);
    }
    }
    add_token(head, tail, buffer, "OPERATOR");

    return 1;
}