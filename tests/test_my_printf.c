/*
** EPITECH PROJECT, 2020
** test
** File description:
** test
*/

#include <stdio.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include "print.h"

Test(my_printf, simple_string, .init=cr_redirect_stdout)
{
    my_printf(" hello world ");
    cr_assert_stdout_eq_str(" hello world ");
}

Test(my_printf, simple_str, .init=cr_redirect_stdout)
{
    char *str = "helloworld";

    my_printf("%s", str);
    cr_assert_stdout_eq_str("helloworld", "");
}

Test(my_printf, simple_int, .init=cr_redirect_stdout)
{
    my_printf("%d", 10) ;
    cr_assert_stdout_eq_str("10", "");
}

Test(my_printf, simple, .init=cr_redirect_stdout)
{
    my_printf("%d%s", 10, "hello");
    cr_assert_stdout_eq_str("10hello", "");
}

Test(my_printf, simple1, .init=cr_redirect_stdout)
{
    my_printf("%o%d%s", 20, 10, "hello");
    cr_assert_stdout_eq_str("2410hello", "");
}

Test(my_printf, simple2, .init=cr_redirect_stdout)
{
    int res = 0;
    my_printf("%%d,%s", 10, "hello");
    cr_assert_eq(0, res);
}

Test(my_printf, simple3, .init=cr_redirect_stdout)
{
    int res = 0;
    my_printf("%%x", 10, "hello");
    my_printf("%%");
    cr_assert_eq(0, res);
}

Test(my_printf, simple4, .init=cr_redirect_stdout)
{
    my_printf("%x%d%s", 200, 10, "hello");
    cr_assert_stdout_eq_str("c810hello", "");
}

Test(my_printf, simple5, .init=cr_redirect_stdout)
{
    my_printf("%o%X%d%s",200, 200, 10, "hello");
    cr_assert_stdout_eq_str("310C810hello", "");
}

Test(my_printf, simple10, .init=cr_redirect_stdout)
{
    my_printf("%b%X%d%s",200, 200, 10, "hello");
    cr_assert_stdout_eq_str("11001000C810hello", "");
}

Test(my_printf, simple6, .init=cr_redirect_stdout)
{
    char str[] = "toto";

    str[1] = 6;
    my_printf("%d%S%X%d%s", -99, str, 200, 10, "hello");
    cr_assert_stdout_eq_str("-99t\\06toC810hello", "");
}

Test(my_printf, simple7, .init=cr_redirect_stdout)
{
    my_printf("%u%X%d%s", 999,200, 10, "hello");
    cr_assert_stdout_eq_str("999C810hello", "");
}

Test(my_printf, simple8, .init=cr_redirect_stdout)
{
    my_printf("%k%i%X%d%s", 20, 200, 10, "hello");
    cr_assert_stdout_eq_str("%k20C810hello", "");
}

Test(my_printf, simple9, .init=cr_redirect_stdout)
{
    my_printf("%u%#x%#X%#o%c%X%d%s", 3, 100, 100, 100, 'a', 200, 10, "hello");
    cr_assert_stdout_eq_str("30x640X640144aC810hello", "");
}

Test(my_printf, simple11, .init=cr_redirect_stdout)
{
    char *str = "hi";
    char str2[20];

    sprintf(str2, "%p", str);
    my_printf("%p",str);
    cr_assert_stdout_eq_str(str2, "");
}

Test(all, test12, .init=cr_redirect_stdout)
{
    int res;
    char *str = NULL;

    res = my_strlen(str);
    cr_assert_eq(0, res);
}

Test(my_printf, simple13, .init=cr_redirect_stdout)
{
    char str2[20];

    sprintf(str2, "%x %X %d", -1, -1, -2147483648);
    my_printf("%x %X %d", -1, -1, -2147483648);
    cr_assert_stdout_eq_str(str2, "");
}

Test(all, test15, .init=cr_redirect_stdout)
{
    int res;

    res = check_all_print("%.d");
    cr_assert_eq(84, res);
}

Test(all, test16, .init=cr_redirect_stdout)
{
    int res;

    res = check_all_print("%#d");
    cr_assert_eq(84, res);
}

Test(all, test17, .init=cr_redirect_stdout)
{
    int res;

    my_printf("%#d", 10);
    res = 84;
    cr_assert_eq(84, res);
}

Test(all, test18, .init=cr_redirect_stdout)
{ 
    int res;

    my_printf("%.x %X %d", -1, -1, -2147483648);
    res = 84;
    cr_assert_eq(84, res);
}

Test(all, test19, .init=cr_redirect_stdout)
{ 
    int res;

    my_printf("%#.x, %s");
    res = 84;
    cr_assert_eq(84, res);
}

Test(all, test20, .init=cr_redirect_stdout)
{ 
    int res;

    my_printf("%.x");
    res = 84;
    cr_assert_eq(84, res);
}