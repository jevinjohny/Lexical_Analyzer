#include "header.h"

int add_token(tok **head, tok **tail, char *lex, char *type, int line_no)
{
    tok *new = malloc(sizeof(tok));

    if (!new)
    {
        printf("Memory allocation by malloc failed\n");
        return 0;
    }

    strcpy(new->lex, lex);
    strcpy(new->type, type);

    new->line_no = line_no;
    new->next = NULL;

    if (*head == NULL)
    {
        *head = new;
        *tail = new;
        return 1;
    }
    else
    {
        (*tail)->next = new;
        *tail = new;
    }
    return 1;
}

int print_token(tok *head)
{
    if (head == NULL)
    {
        printf("Tokens are empty\n");
        return 0;
    }

    tok *temp = head;

    while (temp)
    {
        printf("Token type:%s, Token:%s, Line no %d\n", temp->type, temp->lex, temp->line_no);
        temp = temp->next;
    }

    return 1;
}