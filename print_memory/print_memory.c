#include <unistd.h>


void    print_hex(unsigned char i) {

    char *hex;

    hex = "0123456789abcdef";
    if (i >= 16) {
        print_hex(i / 16);
    }
    write(1, &hex[i % 16], 1);

}

void    print_char(unsigned char c)
{
    if (c >= ' ' && c <= '~')
        write(1, &c, 1);
    else
        write(1, ".", 1);
}

void	print_memory(const void *addr, size_t size)
{
    int i;
    int k;
    int t;
    unsigned char *tmp;

    i = 0;
    tmp = (unsigned char *)addr;
    while (i < size)
    {
        t = i;
        k = -1;
        while (++k < 16)
        {
            if (i < size) {
                if (tmp[i] < 16)
                    write(1, "0", 1);
                print_hex(tmp[i++]);
            }
            else
                write(1, "  ", 2);
            if ((k + 1) % 2 == 0)
                write(1, " ", 1);
        }
        i = t;
        while (k-- > 0  && i < size)
            print_char(tmp[i++]);
        write(1, "\n", 1);
    }
}

int main() {

    int	tab[10] = {0, 23, 150, 255,
                      12, 16,  21, 42};
    print_memory(tab, sizeof(tab));
    return 0;
}