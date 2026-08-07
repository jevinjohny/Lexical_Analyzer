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

void scan_preprocessor(tok **head, tok **tail, FILE *fp, int *line_no);
int add_token(tok **head, tok **tail, char *lex, char *type, int line_no);
int print_token(tok *head);
int keywordcheck(char *str);
void lexer(tok **head, tok **tail, FILE *fp);
int scan_operator(tok **head, tok **tail, FILE *fp, char first_chara, int line_no);
void special_symbols(tok **head, tok **tail, char first_chara, int line_no);
void scan_char_constant(tok **head, tok **tail, FILE *fp, int line_no);
void scan_string_literal(tok **head, tok **tail, FILE *fp, int line_no);
void skip_comment(FILE *fp, int *line_no);

#endif