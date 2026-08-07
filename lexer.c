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
    char ch;

    while ((ch = fgetc(fp)) != EOF)
    {
        if (isalpha(ch)) // it might be a word
        {
            char buffer[50];
            int index = 0;

            while (isalnum(ch))
            {
                buffer[index++] = ch;

                ch = fgetc(fp);
            }

            buffer[index] = '\0';

            if (keywordcheck(buffer))
            {
                add_token(head, tail, buffer, "KEYWORD");
            }
            else
            {
                add_token(head, tail, buffer, "IDENTIFIER");
            }

            ungetc(ch, fp); // puts back the unwanted character at last

            printf("%s\n", buffer);
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
                buffer[index++] = ch;

                ch = fgetc(fp);
            }
            buffer[index] = '\0';

            if (dot <= 1) // if dot is more than 1 it is not a constant
            {
                add_token(head, tail, buffer, "CONSTANT");
            }
            ungetc(ch, fp);
        }
        else if (ch == '\'')
        {
            scan_char_constant(head, tail, fp);
        }
        else if (strchr("+-*/%=!<>&|^?:", ch))
        {
            scan_operator(head, tail, fp, ch);
        }
        else if (strchr("(){}[];,.", ch))
        {
            special_symbols(head, tail, ch);
        }
    }
}