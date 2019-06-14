#include <unistd.h>
#include <stdlib.h>

/*
 * Проверяем можно ли поставить королеву на поле
 * не поставив под удар другие королевы
 * если можно возвращаем 1, если нет - 0
 */
int can_we_put_queen(char **map, char y, char x)
{
    int i;
    int k;

    i = -1;
    k = -1;
    while(++i < 8) {
        if (map[i][x] == '#')
            return (0);
    }
    while (++k < 8) {
        if (map[y][k] == '#')
            return (0);
    }
    i = y;
    k = x;
    while (i < 8 && k < 8) {
        if(map[i++][k++] == '#')
            return (0);
    }
    i = y;
    k = x;
    while (i > -1 && k < 8) {
        if(map[i--][k++] == '#')
            return (0);
    }
    i = y;
    k = x;
    while (i > -1 && k > -1) {
        if(map[i--][k--] == '#')
            return (0);
    }
    i = y;
    k = x;
    while (i > 0 && k < 8) {
        if(map[i--][k++] == '#')
            return (0);
    }
    return (1);
}
/*
 * Непосредственно рекурсивный алгоритм расстановки королев.
 * Цикл ваил с ксловием у<8 нужен для выхода из рекурсии
 * после того как пройдены 8 строк.
 */
int put_queens_in_map(char **map, char y)
{
    int x;

    x = 0;
    while (y < 8)
    {
        if(can_we_put_queen(map, y, x))
        {
            map[y][x] = '#';
            if (put_queens_in_map(map, y + 1))
                return (1);
            else {
                map[y][x] = '.';
                if(++x > 7)
                    return (0);
            }
        }
        else
            if(++x > 7)
                return (0);
    }
    return (1);
}
/*
 * Инициализируем шахматную доску.
 * Выделяем память и забиваем её точками
 */
char **init_map()
{
    int y;
    int x;
    int i;
    char **map;

    i = -1;
    if (!(map = (char **)malloc(sizeof(char *) * 8)))
        return (NULL);
    while(++i < 8)
        if (!(map[i] = (char *) malloc(8)))
            return (NULL);
    y = -1;
    while (++y < 8)
    {
        x = -1;
        while (++x < 8)
            map[y][x] = '.';
    }
    return (map);
}
/*
 * Функция очистки памяти.
 * Так, для галочки
 */
void free_map(char ***map)
{
    int i;

    i = -1;
    while(++i < 8)
    {
        free(*map[i]);
        *map[i] = NULL;
    }
    free(*map);
    *map = NULL;
}

/*
 * Распечатка шахматного поля
 */
void print_map(char **map)
{
    int y;
    int x;

    y = -1;
    while (++y < 8)
    {
        x = -1;
        write(1, "|", 1);
        while (++x < 8) {
            write(1, &map[y][x], 1);
            write(1, "|", 1);
        }
        write(1, "\n", 1);
    }
}
/*
 * Всё это запускаем. Вуаля. Работает.
 */
int start()
{
    char **map;
    if (!(map = init_map()))
        return (1);
    put_queens_in_map(map, 0);
    print_map(map);
    free_map(&map);
    return (0);
}

int main() {
    return (start());
}