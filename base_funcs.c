#include "base_funcs.h"

const char eight[] = {'0','1','2','3','4','5','6','7'};
const char sixteen[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};

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