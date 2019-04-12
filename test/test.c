#include <libftprintf.h>
#include <stdio.h>

int main(void)
{
	int resf = ft_printf("Hello world! %-50s, %sz\n", "a", "Hello");
	int resr = printf("Hello world! %-50s, %sz\n", "a", "Hello");
	printf("fake %d\nreal %d\n", resf, resr);
}