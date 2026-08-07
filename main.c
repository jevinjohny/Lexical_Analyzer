#include "header.h"

int main()
{
    tok *head = NULL;
    tok *tail = NULL;

    FILE *fp;
    fp = fopen("input.txt", "r");

    if (fp == NULL)
    {
        printf("file not found\n");
        return 0;
    }

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
                add_token(&head, &tail, buffer, "KEYWORD");
            }
            else
            {
                add_token(&head, &tail, buffer, "IDENTIFIER");
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
                add_token(&head, &tail, buffer, "CONSTANT");
            }
            ungetc(ch, fp);
        }
    }

    print_token(head);

    return 0;
}