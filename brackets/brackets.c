#include <unistd.h>
#include <stdio.h>
/*
 * Функция удаляет 1 символ (первый) из строки
 */
void remove_char(char *str)
{
    while(*str)
    {
        str[0] = str[1];
        str++;
    }
    *str = 0;
}

/*
 * Функция возвращает тип скобки
 * тип скобки / 10 - вернёт вид скобки
 * () или {} или []
 * с помощью остаток от деления на 10 мы узнаём какая скобка - 
 * открывающаяся или закрывающаяся.
 */
int bracket_type(char c)
{
    if (c == '(')
        return (11);
    if(c == ')')
        return (12);
    if (c == '[')
        return (21);
    if(c == ']')
        return (22);
    if (c == '{')
        return (31);
    if (c == '}')
        return (32);
    return (0);
}

/*
 * Функция удаляет из строки все "некскобочные" символы
 */
void remove_not_brackets(char *str)
{
    int i;

    i = 0;
    while (str[i])
        if (!bracket_type(str[i]))
            remove_char(&str[i]);
        else
            ++i;
}

/*
 * Проверка количества скобок.
 * Если скобка открывающаяся, счётчик соответствующий скобке,
 * увеличивается, иначе - уменьшается.
 * Если счётчик ушёл в минус - значит строка невалидная,
 * функция вернёт 0. Если после подсчёта скобочек хотя бы один из
 * счётчиков не равен нулю - значит строка невалидная.
 */
int check_valid_count(char *str)
{
    int t;
    int br1;
    int br2;
    int br3;

    br1 = 0;
    br2 = 0;
    br3 = 0;
    while (*str)
    {
        t = bracket_type(*str);
        if (t / 10 == 1)
            (t % 10 == 1)? ++br1 : --br1;
        if (t / 10 == 2)
            (t % 10 == 1)? ++br2 : --br2;
        if (t / 10 == 3)
            (t % 10 == 1)? ++br3 : --br3;
        if (br1 < 0 || br2 < 0 || br3 < 0)
            return (0);
        ++str;
    }
    if (!br1 && !br2 && !br3)
        return (1);
    return (0);
}

/*
 * Проверка порядка. При встрече закрывающейся скобки проверяется
 * является ли предыдущая скобка одного с ней типа. Если нет - такая строка невалидная,
 * функция вернёт 0.
 * Если встречены верно закрывающиеся скобки - то они удаляются из строки.
 */
int check_valid_order(char *str)
{
    int i;

    i = 0;
    while(str[i + 1])
    {
        if (bracket_type(str[i + 1]) % 10 == 2) {
            if (bracket_type(str[i]) / 10 != bracket_type(str[i + 1]) / 10)
                return (0);
            else {
                remove_char(&str[i]);
                remove_char(&str[i]);
                --i;
            }
        }else
            ++i;
    }
    return (1);
}

/*
 * Собственно функция проверки которую будем вызывать
 * из функции мэйн применительно к каждому параметру программы
 */
void start_checking(char *str)
{
    remove_not_brackets(str);
    if (check_valid_count(str) && check_valid_order(str))
        write (1, "OK\n", 3);
    else
        write(1, "Error\n", 6);
}

int main(int size, char **args)
{
    if (size < 2)
        write(1, "\n", 1);
    else {
        while (--size && ++args) {
            if (**args == 0)
                write(1, "OK\n", 3);
            else
                start_checking(*args);
        }
    }
    return 0;
}
