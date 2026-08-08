# Lexical Analyzer in C

A compiler front-end project that performs **lexical analysis of C source code**. The lexer reads a C source file, identifies different types of tokens, stores them using a linked list, tracks line numbers, and reports invalid tokens.

## Features

* Keyword recognition
* Identifier detection
* Integer and floating-point constant detection
* Character constant detection
* String literal detection
* Escape sequence handling in character constants and string literals
* Operator detection
* Special symbol detection
* Preprocessor directive detection
* Single-line and multi-line comment handling
* Line number tracking
* Invalid token and syntax error detection
* CRLF (`\r\n`) line-ending handling
* Token storage using a linked list
* Token count and category-wise token summary
* Dynamic memory allocation for tokens

## Token Types

The lexer currently recognizes the following token categories:

* `KEYWORD`
* `IDENTIFIER`
* `CONSTANT`
* `CHAR_CONSTANT`
* `STRING_LITERAL`
* `OPERATOR`
* `SPECIAL_SYMBOL`
* `PREPROCESSOR_DIRECTIVE`
* `ERROR`

## Error Handling

The lexer detects and reports invalid lexical constructs such as:

* Invalid numeric constants: `12.3.4`
* Invalid alphanumeric constants: `123abc`
* Unterminated character constants
* Unterminated string literals
* Invalid/unknown symbols
* Invalid escape sequences

Invalid tokens are stored with the token type `ERROR`.

## Token Storage

Tokens are dynamically allocated and stored in a **singly linked list**.

Each token contains:

```c
typedef struct token
{
    char lex[50];
    char type[30];
    int line_no;
    struct token *next;
} tok;
```

The linked-list structure allows tokens to be stored dynamically as they are identified.

## Token Statistics

After lexical analysis, the lexer displays:

* Individual tokens
* Token type
* Token value
* Line number
* Total number of tokens
* Count of each token category

Example:

```text
========== TOKEN SUMMARY ==========
KEYWORD               : 8
IDENTIFIER            : 14
CONSTANT              : 8
CHAR_CONSTANT         : 1
STRING_LITERAL        : 1
OPERATOR              : 13
SPECIAL_SYMBOL        : 24
PREPROCESSOR_DIRECTIVE: 1
ERROR                 : 0
-----------------------------------
TOTAL TOKENS          : 70
===================================
```

## Concepts Used

* C programming
* File handling
* Structures
* Pointers
* Dynamic memory allocation
* Linked lists
* Character classification functions
* String handling
* Lexical analysis
* Error handling
* Modular programming

## Project Structure

```text
lexical/
├── header.h
├── main.c
├── lexer.c
├── token.c
├── scanner.c
├── input.txt
└── ...
```

## Compilation

Compile all C source files using:

```bash
gcc *.c
```

Run the executable:

```bash
./a.out
```

## Sample Input

```c
#include <stdio.h>

int main()
{
    int count = 10;
    float speed = 25.5;
    char grade = 'A';

    count++;

    if (count >= 10 && speed != 0)
    {
        printf("Vehicle speed is high\n");
    }

    return 0;
}
```

The lexer processes the source code and generates a token stream containing the recognized token type, lexeme, and line number.

## Future Improvements

* Improve lexical validation for additional C constants
* Add more comprehensive escape-sequence validation
* Improve buffer overflow protection
* Add hexadecimal, octal, and scientific-notation constants
* Improve error reporting with detailed error messages
* Add automated test cases
* Improve memory cleanup and token-list management
* Extend the project toward syntax analysis
