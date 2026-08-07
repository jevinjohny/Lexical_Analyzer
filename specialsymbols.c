#include "header.h"

void special_symbols(tok **head, tok **tail, char first_chara, int line_no)
{
    switch (first_chara)
    {
    case '(':
        add_token(head, tail, "(", "SPECIAL_SYMBOL", line_no);
        break;
    case ')':
        add_token(head, tail, ")", "SPECIAL_SYMBOL", line_no);
        break;
    case '[':
        add_token(head, tail, "[", "SPECIAL_SYMBOL", line_no);
        break;
    case ']':
        add_token(head, tail, "]", "SPECIAL_SYMBOL", line_no);
        break;
    case '{':
        add_token(head, tail, "{", "SPECIAL_SYMBOL", line_no);
        break;
    case '}':
        add_token(head, tail, "}", "SPECIAL_SYMBOL", line_no);
        break;
    case ';':
        add_token(head, tail, ";", "SPECIAL_SYMBOL", line_no);
        break;
    case ',':
        add_token(head, tail, ",", "SPECIAL_SYMBOL", line_no);
        break;
    case '.':
        add_token(head, tail, ".", "SPECIAL_SYMBOL", line_no);
        break;
    }
}