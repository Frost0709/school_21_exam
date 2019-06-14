#include "sudoku.h"

/*
 * Распечатка карты
 */
void print_map(char **map)
{
    int i;
    int k;
    char c;

    i = -1;
    while (++i < 9)
    {
        k = -1;
        write(1, "|", 1);
        while (++k < 9) {
            c = map[i][k];
            write(1, &c, 1);
            write(1, "|", 1);
        }
        write(1, "\n", 1);
    }
}

int main(int args, char **argv) {

    if(!is_valid(args, argv))
    {
        write(1, "Error\n", 6);
        return (0);
    }
    if(!try_to_fill_map(++argv, 0, 0))
    {
        write(1, "Error\n", 6);
        return (0);
    }
    print_map(argv);
    return 0;
}