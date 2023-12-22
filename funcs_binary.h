#ifndef FUNCS_H
#define FUNCS_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h> 
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



typedef struct{
    char first[30];
    char second[30];
    char operation[2];
} Nums;
Nums get_values(char *str);
int powerer(int base,int exponent);
int indexof(int c);
int convert_to_tenth(char *str,int base);

int check_is_double(char* str);
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