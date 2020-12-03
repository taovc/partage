/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "my.h"

char *my_itoa(int n){  
    int i = 0, isNegative = 0;
    static char s[100];
    if((isNegative = n) < 0){
        n = -n;
    }
    do {
        s[i++] = n % 10 + '0';
        n = n / 10;
    } while(n > 0);
    if(isNegative < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    return my_revstr(s);
}