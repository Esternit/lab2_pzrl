#ifndef FUNCS_H
#define FUNCS_H
enum eOperations
{
    PLUS = 43,
    MINUS = 45,
    MULTIPLIC = 42,
    PERCENT = 37,
    AND = 38,
    OR = 124,
    XOR = 94,
    NOT = 126

};

const char eight[] = {'0','1','2','3','4','5','6','7'};
const char sixteen[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};

typedef struct{
    char first[30];
    char second[30];
    char operation[2];
} Nums;
Nums get_values(char *str);
int powerer(int base,int exponent);
int indexof(int c);
int convert_to_tenth(char *str,int base);
int check_in_mas(int c, int type);
int check_is_double(char* str);
int check_is_eight(char* str);
int check_is_sixteen(char* str);
void printer(int base,int result);
void addition(Nums args,int base);
void subsraction(Nums args,int base);
void multiplication(Nums args,int base);
void percentage(Nums args,int base);
void ander(Nums args,int base);
void orer(Nums args,int base);
void xorer(Nums args,int base);
void noter(Nums args,int base);

#endif