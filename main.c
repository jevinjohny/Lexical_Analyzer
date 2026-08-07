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

    lexer(&head, &tail, fp);

    print_token(head);

    return 0;
}