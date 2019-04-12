#include <libftprintf.h>
#include <stdio.h>

int main(void)
{
	char *test = "Hello world";
	int resf = ft_printf("Hello world! %+05d, %6.4d\n", -100, -432);
	int resr = printf("Hello world! %+05d, %6.4d\n", -100, -432);
	ft_printf("Hello world! %5u, %-5u\n", 100, 5432);
	printf("Hello world! %5u, %-5.5u\n", 100, 5432);
	printf("fake %d\nreal %d\n", resf, resr);
	//while(1);
}