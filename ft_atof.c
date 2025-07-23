#include "fractol.h"

static int ft_isspace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || 
            c == '\v' || c == '\f' || c == '\r');
}

static int digit(char c)
{
    return (c >= '0' && c <= '9');
}

double ft_atof(const char *str)
{
    double result;
    double fraction;
    int sign;
    int i;

    result = 0.0;
    fraction = 1.0;
    sign = 1;
    i = 0;
    
    while (ft_isspace(str[i]))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (digit(str[i]))
    {
        result = result * 10.0 + (str[i] - '0');
        i++;
    }
    if (str[i] == '.')
    {
        i++;
        while (digit(str[i]))
        {
            fraction /= 10.0;
            result += (str[i] - '0') * fraction;
            i++;
        }
    }
    return (result * sign);
}