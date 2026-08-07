#ifndef HEADER_H
#define HEADER_H

#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct token
{
    char lex[50];
    char type[30];
    int line_no;
    struct token *next;
} tok;

int add_token(tok **head, tok **tail, char *lex, char *type);
int print_token(tok *head);
int keywordcheck(char *str);
void lexer(tok **head, tok **tail, FILE *fp);
int scan_operator(tok **head, tok **tail, FILE *fp, char first_chara);
void special_symbols(tok **head, tok **tail, char first_chara);

#endif