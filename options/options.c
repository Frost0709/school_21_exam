#include <unistd.h>

/*
 * Функция возвращает индекс символа в массиве опшнс
 * или -1 если такого символа нет
 */
int fing_index_in_arr(char *options, char c)
{
    int i;

    i = 0;
    while (i < 26)
    {
        if(options[i] == c)
            return (i);
        ++i;
    }
    return (-1);
}

/*
 * Функция распечатки интеджера длиной 4 байта
 * с отсечкой по 8 разрядов
 */
void print_int(int i)
{
    int k;
    int t;
    char r;

    t = 1;
    k = 32;
    while (k--)
    {
        r = ((i >> k) & 1u) + 48;
        write (1, &r, 1);
        if (t++ % 8 == 0)
            write(1, " ", 1);
    }
}

int main(int args, char **argv) {

    int t;
    int k;
    char *options;

    k = 0;
    options = "abcdefghijklmnopqrstuvwxyz\n";
    if (args == 1)
    {
        write(1, options, 27);
        return (0);
    }
    while (args--)
    {
        if (**argv == '-')
        {
            if (*(*argv + 1) == 'h') {
                write(1, options, 27);
                return (0);
            }
            ++(*argv);
            while (**argv)
            {
                if ((t = fing_index_in_arr(options, **argv)) == -1) {
                    write(1, "Invalid Option\n", 15);
                    return (0);
                }
                k = k | (1 << t);
                ++(*argv);
            }
        }
        ++argv;
    }
    print_int(k);
    return (0);
}