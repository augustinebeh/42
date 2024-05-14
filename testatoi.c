#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int     ft_atoi(const char *str)
{
    int num;
    int sign;

    num = 0;
    sign = 1;
    while (*str == ' ')
        str++;
    if (*str == '-')
        sign = - 1;
    if (*str == '-' || *str == '+')
        str++;
    while (*str >= '0' && *str <= '9')
        num = num * 10 + *str++ - '0';
    return (num * sign);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int val;
        val = atoi(argv[1]);
        printf("------------------------------------------------\n");
        printf("Input value = %s\nMy Atoi Value: %d\nReal Atoi Value = %d\n", argv[1], ft_atoi(argv[1]), val);
        char* ans;
        ans = "yes";
        if (ft_atoi(argv[1]) != val)
        {
            ans = "no";
        }
        printf("Is my ATOI value equivalent to the REAL ATOI: %s\n------------------------------------------------\n", ans);
        }
}