#include <libftprintf.h>
#include <stdio.h>

int main(void)
{
	int resf = ft_printf("Hello world! %5c, %-5c\n", 0, 'b');
	int resr = printf("Hello world! %5c, %-5c\n", 0, 'b');
	printf("fake %d\nreal %d\n", resf, resr);
}