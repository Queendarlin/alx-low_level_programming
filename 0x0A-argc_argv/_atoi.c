#include <stdio.h>
 
/**
 * _atoi - A simple atoi() function
 * @str: parameter
int _atoi(char *str)
{
    int res = 0;

    for (int i = 0; str[i] != ''; ++i)
        res = res * 10 + str[i] - '0';
 
    return res;
}
