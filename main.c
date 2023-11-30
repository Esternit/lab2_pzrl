#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "funcs.h"





int main(int args, char ** kvargs)
{
    char operation[30];
    printf("Input operation: ");
    gets(operation);
    printf("%s %d %c\n",operation,strlen(operation),operation[3]);
    enum eOperations operator;
    Nums res;
    int base;
    if(check_is_double(operation) == 0)
    {
        base = 2;
    }
    else if(check_is_eight(operation) == 0)
    {
        base = 8;
    }
    else if(check_is_sixteen(operation) == 0)
    {
        base = 16;
    }
    else if(operation[0] != '~')
    {
        printf("Systems do not match");
        return 1;
    }

    if(operation[0] != '~')
    {
        res = get_values(operation);
        operator =res.operation[0];
        
    }
    else
    {
        char *temp;
        base = 2;
        if(operation[0] != '~' || operation[1] == ' ')
        {
            printf("Not valid unput");
            return 1;
        }
        temp = strtok (operation,"~");
        strcpy(res.first,temp);
        strcpy(res.operation,"~");
        strcpy(res.second,"No");
        operator = 126;
        printf("%s %s", res.first,res.operation);
    }
    switch (operator)
    {
    case PLUS:
        addition(res,base);
        break;
    case MINUS:
        subsraction(res,base);
        break;
    case MULTIPLIC:
        multiplication(res,base);
        break;
    case PERCENT:
        percentage(res,base);
        break;
    case AND:
        ander(res,base);
        break;
    case OR:
        orer(res,base);
        break;
    case XOR:
        xorer(res,base);
        break;
    case NOT:
        noter(res,base);
        break;
    default:
        printf("Operation not identified");
        break;
    }

    return 0;
}