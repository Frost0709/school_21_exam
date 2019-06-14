/*
 * Проверяем возможность вставить числа в мапу
 * Проверяем встречается ли число num в клетках по горизонтали или вертикали
 * В случае если можно вставить число возвращается число num
 * В случае если вставить число нельзя возвращается 0
 */
char can_we_insert_num_check_yx(char num, char **map, char y, char x)
{
    int i;

    i = -1;
    while (++i < 9)
        if (map[y][i] == num)
            return (0);
    i = -1;
    while (++i < 9)
        if (map[i][x] == num)
            return (0);
    return (num);
}

/*
 * Проверяем возможность вставить число в мапу
 * Определяем начальные координаты проверяемого квадрата 3х3
 * Если возможно вставить число функция верёнт num
 * Если вставка невоозможна функция вернёт 0
 */
char can_we_insert_num_check_square(char num, char **map, char y, char x)
{
    char i;
    char k;
    char start_y;
    char start_x;

    start_y = (y / 3) * 3;
    start_x = (x / 3) * 3;
    i = -1;
    while (++i < 3)
    {
        k = -1;
        while (++k < 3)
            if (map[start_y + i][start_x + k] == num)
                return (0);
    }
    return (num);
}
/*
 * Функция объединяет 2 проверки. Просто для удобства
 */
char check_position(char num, char **map, char y, char x)
{
    if (!can_we_insert_num_check_yx(num, map, y, x))
        return (0);
    if (!can_we_insert_num_check_square(num, map, y, x))
        return (0);
    return (num);
}
/*
 * Сдвиг координат в мапе на следующую позицию
 * Возвращает 1 если сдвиг успешен и 0 - если сдвиг невозможен
 */
char next_cord(char y, char x, char *next_y, char *next_x)
{
    if (x < 8)
    {
        *next_y = y;
        *next_x = x + 1;
        return (1);
    }
    if (y < 8)
    {
        *next_y = y + 1;
        *next_x = 0;
        return (1);
    }
    return (0);
}

/*
 * Рекурсивный алгоритм перебора всех значений.
 */
char try_to_fill_map(char **map, char y, char x)
{
    char next_y;
    char next_x;
    char i;

    i = -1;
    if (map[y][x] == '.')
    {
        while (++i < 9)
        {
            if (check_position('0' + i + 1, map, y, x))
            {
                map[y][x] = '0' + i + 1;
                if (!next_cord(y, x, &next_y, &next_x))
                    return (1);
                if (!try_to_fill_map(map, next_y, next_x))
                    map[y][x] = '.';
                else
                    return (1);
            }
        }
        return (0);
    }
    if (!next_cord(y, x, &next_y, &next_x))
        return (1);
    return (try_to_fill_map(map, next_y, next_x));
}

