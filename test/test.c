#include <libftprintf.h>
#include <stdio.h>

int main(void)
{
	char *test = "Hello world";
	ft_printf("%08.3i\n", -8473); 
	printf("%08.3i\n", -8473);
	ft_printf("%0 -10.5i\n", -215); 
	printf("%0 -10.5i\n", -215);
	//while(1);
}