#include "header.h"

void special_symbols(tok **head, tok **tail, char first_chara)
{
    switch (first_chara)
    {
    case '(':
        add_token(head, tail, "(", "SPECIAL_SYMBOL");
        break;
    case ')':
        add_token(head, tail, ")", "SPECIAL_SYMBOL");
        break;
    case '[':
        add_token(head, tail, "[", "SPECIAL_SYMBOL");
        break;
    case ']':
        add_token(head, tail, "]", "SPECIAL_SYMBOL");
        break;
    case '{':
        add_token(head, tail, "{", "SPECIAL_SYMBOL");
        break;
    case '}':
        add_token(head, tail, "}", "SPECIAL_SYMBOL");
        break;
    case ';':
        add_token(head, tail, ";", "SPECIAL_SYMBOL");
        break;
    case ',':
        add_token(head, tail, ",", "SPECIAL_SYMBOL");
        break;
    case '.':
        add_token(head, tail, ".", "SPECIAL_SYMBOL");
        break;
    }
}