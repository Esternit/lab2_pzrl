#include "funcs_sixteen.h"
#include "base_funcs.h"

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