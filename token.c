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
    int total = 0;
    int KEYWORD = 0;
    int IDENTIFIER = 0;
    int CONSTANT = 0;
    int CHAR_CONSTANT = 0;
    int STRING_LITERAL = 0;
    int OPERATOR = 0;
    int SPECIAL_SYMBOL = 0;
    int PREPROCESSOR_DIRECTIVE = 0;
    int ERROR = 0;
    tok *temp = head;

    while (temp)
    {
        printf("Token type:%s, Token:%s, Line no %d\n", temp->type, temp->lex, temp->line_no);
        if (strcmp("KEYWORD", temp->type) == 0)
        {
            KEYWORD++;
        }
        else if (strcmp("IDENTIFIER", temp->type) == 0)
        {
            IDENTIFIER++;
        }
        else if (strcmp("CONSTANT", temp->type) == 0)
        {
            CONSTANT++;
        }
        else if (strcmp("CHAR_CONSTANT", temp->type) == 0)
        {
            CHAR_CONSTANT++;
        }
        else if (strcmp("STRING_LITERAL", temp->type) == 0)
        {
            STRING_LITERAL++;
        }
        else if (strcmp("OPERATOR", temp->type) == 0)
        {
            OPERATOR++;
        }
        else if (strcmp("SPECIAL_SYMBOL", temp->type) == 0)
        {
            SPECIAL_SYMBOL++;
        }
        else if (strcmp("PREPROCESSOR_DIRECTIVE", temp->type) == 0)
        {
            PREPROCESSOR_DIRECTIVE++;
        }
        else if (strcmp("ERROR", temp->type) == 0)
        {
            ERROR++;
        }
        total++;
        temp = temp->next;
    }

    printf("\n========== TOKEN SUMMARY ==========\n");
    printf("KEYWORD              : %d\n", KEYWORD);
    printf("IDENTIFIER           : %d\n", IDENTIFIER);
    printf("CONSTANT             : %d\n", CONSTANT);
    printf("CHAR_CONSTANT        : %d\n", CHAR_CONSTANT);
    printf("STRING_LITERAL       : %d\n", STRING_LITERAL);
    printf("OPERATOR             : %d\n", OPERATOR);
    printf("SPECIAL_SYMBOL       : %d\n", SPECIAL_SYMBOL);
    printf("PREPROCESSOR_DIRECTIVE: %d\n", PREPROCESSOR_DIRECTIVE);
    printf("ERROR                : %d\n", ERROR);
    printf("-----------------------------------\n");
    printf("TOTAL TOKENS         : %d\n", total);
    printf("===================================\n");

    return 1;
}