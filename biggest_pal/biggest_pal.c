#include <unistd.h>

int str_len(char *str)
{
    int i;

    i = 0;
    while (str[i])
        ++i;
    return (i);
}

/*
 * Функция сравнивает две строки
 * Вторая строка идёт в обратном порядке
 * Возвращает длинну строки в случае успеха
 * 0 - в случае если строка не палиндром
 */
int equals_revers(char *str, char *rev_str)
{
    int i;

    i = 0;
    while(str + i < rev_str - i) {
        if (str[i] != rev_str[-i])
            return (0);
        ++i;
    }
    if (str + i == rev_str - i)
        return (i * 2 + 1);
    return (i * 2);
}

/*
 * Самый большой палиндром
 */
void biggest_pal(char *start)
{
    int i;
    int k;
    int t;
    int count;
    char *result;
    char *finish;

    count = 0;
    result = 0;
    finish = start + str_len(start) - 1;
    i = -1;
    while(start[++i])
    {
        k = -1;
        while (start + i < finish - ++k) {
            if ((t = equals_revers(start + i, finish - k))) {
                if (count <= t){
                    count = t;
                    result = start + i;
                }
            }
        }
    }
    write(1, result, count);
}

int main(int args, char **argv)
{
    if (args == 2)
        biggest_pal(argv[1]);
    write(1, "\n", 1);
    return (0);
}
