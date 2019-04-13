#include <libftprintf.h>
#include <stdio.h>

int main(void)
{
	char *test = "Hello world";
	ft_printf("%+.0d\n", 0); 
	printf("%+.0d\n", 0);
	ft_printf("%+5.d\n", 0); 
	printf("%+5.d\n", 0);
	//while(1);
}