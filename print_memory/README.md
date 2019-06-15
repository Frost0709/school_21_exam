Распечатка памяти. <br />

Assignment name  : print_memory<br />
Expected files   : print_memory.c<br />
Allowed functions: write<br />
--------------------------------------------------------------------------------<br />

Write a function that takes (const void *addr, size_t size), and displays the<br />
memory as in the example.<br />

Your function must be declared as follows:<br />

void	print_memory(const void *addr, size_t size);<br />

---------<br />
$> cat main.c<br />
void	print_memory(const void *addr, size_t size);<br />

int	main(void)<br />
{<br />
	int	tab[10] = {0, 23, 150, 255,<br />
	              12, 16,  21, 42};<br />
<br />
	print_memory(tab, sizeof(tab));<br />
	return (0);<br />
}<br />
$> gcc -Wall -Wall -Werror main.c print_memory.c && ./a.out | cat -e<br />
0000 0000 1700 0000 9600 0000 ff00 0000 ................$<br />
0c00 0000 1000 0000 1500 0000 2a00 0000 ............*...$<br />
0000 0000 0000 0000                     ........$<br />
