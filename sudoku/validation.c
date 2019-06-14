#include "sudoku.h"

/*
 * Подсчёт длины строки
 */
int str_len(char *str)
{
    int len;

    len = 0;
    while (str[len])
        ++len;
    return (len);
}

/*
 * Проверка на валидные входные символы
 * Допустимы только числа от '1' до '9' и '.'
 */
char check_valid_chars(char **map)
{
    char i;
    char k;

    i = -1;
    while (++i < 9)
    {
        k = -1;
        while (++k < 9)
            if (map[i][k] != '.' && !(map[i][k] >= '1' && map[i][k] <= '9'))
                return (0);
    }
    return (1);
}

/*
 * Валидация по количеству аргументов
 * По длине каждого аргумента
 * 1 - строка валидна.
 * 0 - невалидна
 */
char is_valid(int args, char **map)
{
    char i;
    char k;

    if (args != 10)
        return (0);
    i = -1;
    ++map;
    while (++i < 9)
        if (str_len(map[i]) != 9)
            return (0);
    if (!check_valid_chars(map))
        return (0);
    return (1);
}
