#include "funcs.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h> 

Nums get_values(char *str)
{
    char *temp;
    char *firststr;
    char *secondstr;
    char *operation;
    temp = strtok (str," ");
    firststr = temp;
    int count =0;
    

    while (temp != NULL)
    {
        temp= strtok (NULL," ");
        
        if(count == 0)
        {
            operation = temp;
            count ++;
        }
        else if(count == 1)
        {
            secondstr = temp;
            break;
        }
        
        
        
    }
    
    Nums obj;
    strcpy(obj.first,firststr);
    strcpy(obj.second,secondstr);
    strcpy(obj.operation,operation);
    return obj;
}


int powerer(int base,int exponent)
{
    int result = 1;
    for(int i = 0;i < exponent;i++)
    {
        result = result * base;
    }
    return result;
}

int indexof(int c)
{
    
    for(int i = 0;i < 16;i++)
    {
        if(c == sixteen[i])
        {
            return i;
        }
    }
    return -1;
}
int convert_to_tenth(char *str,int base)
{
    int res=0;
    char value[3];
    int power = 0;
    int temp;
    
    for(int i = strlen(str)-1; i >= 0;i--)
    {
        if(!isdigit(str[i]))
        {
            if(str[i] != 'x')
            {
                itoa(indexof(str[i]),value,10);
                res = res + atoi(value)*pow(base,power);
            }

        }
        else
        {
            temp = str[i] - '0';
            res = res + temp*powerer(base,power);
        }
        
        power++;

    }
    return res;
}
int check_in_mas(int c, int type)
{
    if(type == 0)
    {
        for(int i = 0;i < 8; i++)
        {
            if(eight[i] == c)
            {
                return 0;
            }
        }
    }
    if(type == 1)
    {
        for(int i = 0;i < 16; i++)
        {
            if(sixteen[i] == c)
            {
                return 0;
            }
        }
    }
    return 1;
}

int check_is_double(char* str)
{
    int length = strlen(str);
    int count_space = 0;
    for(int i = 0;i < length;i++)
    {
        if((count_space == 0 || count_space == 2) && !(isspace(str[i])))
        {
            if(str[i] != '0' && str[i] != '1')
            {
                return 1;
            }
        }
        if(isspace(str[i]))
        {
            count_space = count_space + 1;
        }

    }
    if (count_space != 2)
    {
        return 1;
    }
    return 0;
}

int check_is_eight(char* str)
{
    int length = strlen(str);
    int count_space = 0;
    int just_switched = 0;
    for(int i = 0;i < length;i++)
    {
        if((count_space == 0 || count_space == 2) && !(isspace(str[i])))
        {
            if(just_switched == 0)
            {
                if(str[i] != '0')
                {
                    return 1;
                }
                just_switched = 1;
            }
            else
            {
                if(check_in_mas(str[i],0) == 1)
                {
                    return 1;
                }
            }

        }
        if(isspace(str[i]))
        {
            count_space = count_space + 1;
            just_switched = 0;
        }

    }
    if (count_space != 2)
    {
        return 1;
    }
    return 0;
}

int check_is_sixteen(char* str)
{
    int length = strlen(str);
    int count_space = 0;
    int just_switched = 0;
    int find = 0;
    for(int i = 0;i < length;i++)
    {
        if(str[i] == 'x')
        {
            find = 1;
        }
        if((count_space == 0 || count_space == 2) && !(isspace(str[i])))
        {
            if(just_switched == 0)
            {
                if(str[i] != '0')
                {
                    return 1;
                }
                just_switched = 1;
            }
            else if(just_switched == 1)
            {
                if(str[i] != 'x')
                {
                    return 1;
                }
                just_switched = 2;
            }
            else
            {
                if(check_in_mas(str[i],1) == 1)
                {
                    return 1;
                }
            }

        }
        if(isspace(str[i]))
        {
            count_space = count_space + 1;
            just_switched = 0;
        }

    }
    if (count_space != 2 || find == 0)
    {
        return 1;
    }
    return 0;
}

void printer(int base,int result)
{
    if(base == 8)
    {
        if(result < 0)
        {
            result = ~result + 1;
            printf("-%o (-%d)",result,result);
        }
        else
        {
            printf("%o (%d)",result,result);
        }        
    }
    else if(base == 16)
    {
        if(result < 0)
        {
            result = ~result + 1;
            printf("-0x%X (-%d)",result,result);
        }
        else
        {
            printf("0x%X (%d)",result,result);
        }
    }
    else
    {
        if(result < 0)
        {
            result = ~result + 1;
            char res[sizeof(result)];
            printf("-%s (-%d)", itoa(result,res,2),result);
        }
        else
        {
            char res[sizeof(result)];
            printf("%s (%d)", itoa(result,res,2),result);
        }
    }
}

void addition(Nums args,int base)
{
    int first = convert_to_tenth(args.first,base);
    int second = convert_to_tenth(args.second,base);
    
    int result = first + second;
    printer(base,result);


}

void subsraction(Nums args,int base)
{
    int first = convert_to_tenth(args.first,base);
    int second = convert_to_tenth(args.second,base);
    
    int result = first - second;
    printer(base,result);
    
}

void multiplication(Nums args,int base)
{
    int first = convert_to_tenth(args.first,base);
    int second = convert_to_tenth(args.second,base);
    
    int result = first * second;
    printer(base,result);
    
}

void percentage(Nums args,int base)
{
    int first = convert_to_tenth(args.first,base);
    int second = convert_to_tenth(args.second,base);
    int result = first % second;
    printer(base,result);
    
}

void ander(Nums args,int base)
{
    int first = convert_to_tenth(args.first,base);
    int second = convert_to_tenth(args.second,base);
    
    int result = first & second;
    printer(base,result);
    
}

void orer(Nums args,int base)
{
    int first = convert_to_tenth(args.first,base);
    int second = convert_to_tenth(args.second,base);
    
    int result = first | second;
    printer(base,result);
    
}

void xorer(Nums args,int base)
{
    int first = convert_to_tenth(args.first,base);
    int second = convert_to_tenth(args.second,base);
    
    int result = first ^ second;
    printer(base,result);
    
}

void noter(Nums args,int base)
{
    int first = convert_to_tenth(args.first,base);
    
    int result = ~first;
    printer(base,result);
    
}
