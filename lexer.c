#include "header.h"

int keywordcheck(char *str)
{
    char *keywords[] = {"int", "return", "if", "else", "while", "for", "char", "float", "double", "void"};
    int n = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < n; i++)
    {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

void lexer(tok **head, tok **tail, FILE *fp)
{
    int line_no = 1;
    char ch;

    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == '\r')
        {
            continue;
        }
        else if (ch == '#')
        {
            scan_preprocessor(head, tail, fp, &line_no);
        }
        else if (ch == '\n')
        {
            line_no++;
        }
        else if (isalpha(ch)) // it might be a word
        {
            char buffer[50];
            int index = 0;

            while (isalnum(ch))
            {
                if (ch != '\r')
                {
                    buffer[index++] = ch;
                }

                ch = fgetc(fp);
            }

            buffer[index] = '\0';

            if (keywordcheck(buffer))
            {
                add_token(head, tail, buffer, "KEYWORD", line_no);
            }
            else
            {
                add_token(head, tail, buffer, "IDENTIFIER", line_no);
            }

            ungetc(ch, fp); // puts back the unwanted character at last
        }
        else if (isdigit(ch)) // might be number or constant
        {
            char buffer[50];
            int index = 0;
            int dot = 0;

            while (isdigit(ch) || ch == '.') // handles floating constant
            {
                if (ch == '.')
                {
                    dot++; // counts the no of dot
                }
                if (ch != '\r')
                {
                    buffer[index++] = ch;
                }

                ch = fgetc(fp);
            }
            buffer[index] = '\0';

            if (dot <= 1) // if dot is more than 1 it is not a constant
            {
                add_token(head, tail, buffer, "CONSTANT", line_no);
            }
            ungetc(ch, fp);
        }
        else if (ch == '\'')
        {
            scan_char_constant(head, tail, fp, line_no);
        }
        else if (ch == '"')
        {
            scan_string_literal(head, tail, fp, line_no);
        }
        else if (ch == '/')
        {
            skip_comment(fp, &line_no);
        }
        else if (strchr("+-*/%=!<>&|^?:", ch))
        {
            scan_operator(head, tail, fp, ch, line_no);
        }
        else if (strchr("(){}[];,.", ch))
        {
            special_symbols(head, tail, ch, line_no);
        }
    }
}