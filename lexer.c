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