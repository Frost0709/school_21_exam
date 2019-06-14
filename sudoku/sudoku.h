//
// Created by Ivan on 14.06.2019.
//

#ifndef SUDOKU_SUDOKU_H
#define SUDOKU_SUDOKU_H
#include <unistd.h>

char try_to_fill_map(char **map, char y, char x);
char is_valid(int args, char **map);

#endif //SUDOKU_SUDOKU_H
