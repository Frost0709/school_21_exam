#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void remove_chars(char *str)
{
    int i;

    i = -1;
    while (str[++i])
        str[i] = str[i + 1];
    str[i] = 0;
}

int is_number(char *c)
{
    if (c[0] == '-' || c[0] == '+' && (c[1] != ' ' && c[1]))
        ++c;
    if (c[0] >= '0' && c[0] <= '9') {
        return (1);
    }
    return (0);
}

int is_operand(char c)
{
    if (c == '*' || c == '/' || c == '+' || c =='-' || c == '%')
        return (1);
    return (0);
}

/*
 * Функция используется для удаления подстроки до пробела
 * И пробел тоже удалится
 */
void remove_until_space(char *str)
{
    int i;

    i = 0;
    while (str[i]) {
        if (str[i] != ' ')
            remove_chars(&str[i--]);
        else
            break;
        ++i;
    }
    if (str[i] == ' ')
        remove_chars(&str[i]);
}

/*
 * Функция подсчёта. Возвращает 1 если подсчёт произведён без ошибок
 * 0 - если были ошибки
 */
int  calc(char *str, int *stack)
{
    int pos;
    int i;

    i = -1;
    pos = -1;
    while (str[++i])
    {
        if (is_number(&str[i])) {
            stack[++pos] = atoi(&str[i]);
            remove_until_space(&str[i--]);
        }
        else if (is_operand(str[i]))
        {
            if (pos < 0)
                return (0);
            if (str[i] == '*')
                stack[pos - 1] = stack[pos - 1] * stack[pos];
            else if (str[i] == '/')
                stack[pos - 1] = stack[pos - 1] / stack[pos];
            else if (str[i] == '+')
                stack[pos - 1] = stack[pos - 1] + stack[pos];
            else if (str[i] == '-')
                stack[pos - 1] = stack[pos - 1] - stack[pos];
            else if (str[i] == '%')
                stack[pos - 1] = stack[pos - 1] % stack[pos];
            remove_chars(&str[i--]);
            --pos;
        }
    }
    return (!pos ? 1 : 0);
}

int main(int args, char **argv) {
    int stack[100] = {0};
    if (args == 2)
    {
        if(!calc(argv[1], stack))
            write(1, "Error\n", 6);
        else
            printf("%d\n", stack[0]);
    }
    return (0);
}