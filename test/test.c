#include <libftprintf.h>
#include <stdio.h>

int main(void)
{
	int resf = ft_printf("adsf %10.5s\n", "Hello world");
	printf("\n%10.5s\n", "Hello world");
}