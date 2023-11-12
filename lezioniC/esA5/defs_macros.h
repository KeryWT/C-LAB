// Esempi di macro al posto delle funzioni per is_digit e is_letter

#define is_digit(c)         ( (c)<='9' && (c)>='0')
#define is_letter(c)        ( (c)<='Z' && (c)>='A' || (c)<='z' && (c)>='a')
#define is_whitespace(c)    ( (c)==' ' || (c)=='\n' || (c)=='\r' || (c)=='\t')
typedef unsigned long int counter;
