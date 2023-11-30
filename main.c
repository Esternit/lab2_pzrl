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

const char eight[] = {'0','1','2','3','4','5','6','7'};
const char sixteen[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};

typedef struct{
    char first[30];
    char second[30];
    char operation[2];
} Nums;

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
            itoa(indexof(str[i]),value,10);
            res = res + atoi(value)*pow(base,power);
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
    if (count_space != 2)
    {
        return 1;
    }
    return 0;
}


void addition(Nums args,int base)
{
    int first = convert_to_tenth(args.first,base);
    int second = convert_to_tenth(args.second,base);
    int result = first + second;

}

int main(int args, char ** kvargs)
{
    char operation[30];
    printf("Input operation: ");
    gets(operation);
    printf("%s %d %c\n",operation,strlen(operation),operation[3]);
    printf("%d\n", check_is_sixteen(operation));
    enum eOperations operator;
    Nums res;
    int base;
    if(check_is_double(operation))
    {
        base = 2;
    }
    else if(check_is_eight(operation))
    {
        base = 8;
    }
    else if(check_is_sixteen(operation))
    {
        base = 16;
    }
    else
    {
        printf("Systems do not match");
        return 1;
    }

    if(operation[0] != '~')
    {
        res = get_values(operation);
        operator =res.operation[0];
        
        printf("%d",operator);
    }
    else
    {
        char *temp;
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
        /* code */
        break;
    case MINUS:
        /* code */
        break;
    case MULTIPLIC:
        /* code */
        break;
    case PERCENT:
        /* code */
        break;
    case AND:
        /* code */
        break;
    case OR:
        /* code */
        break;
    case XOR:
        /* code */
        break;
    case NOT:
        /* code */
        break;
    default:
        printf("Operation not identified");
        break;
    }

    return 0;
}