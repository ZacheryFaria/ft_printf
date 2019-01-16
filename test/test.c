#include <stdio.h>
#include <libftprintf.h>
#include <limits.h>
#include <libft.h>

#define A fflush(0);ft_putstr("\t->"); ft_putnbr(a); puts(""); fflush(0);

int
main(void)
{
	int a = 0;


	#ifdef GEN_T
    	a = ft_printf("Hello"); A
		a = ft_printf("a big black man is chasing you"); A
		a = ft_printf(""); A
	#endif

	#ifdef T_C
		a = ft_printf("'a': %c", 97); A
		a = ft_printf("';': %c", ';'); A
		a = printf("%c%c%c%c%c", 'h', 'e', 'l', 'l', 'o'); A
		a = ft_printf("'a': %c", 97); A
		a = ft_printf("'a': %c", 97); A
	#endif

	#ifdef T_D
		a = ft_printf("1: %d", 1); A
		a = ft_printf("12345: %d %d %d %d %d", 1, 2, 3, 4, 5); A
		a = ft_printf("0: %d", 0); A
		a = ft_printf("0 0 0 0: %d %d %d %d", 0, 0, 0, 0); A
		a = ft_printf("-12: %d", -12); A
		a = ft_printf("INT_MIN: %d", INT_MIN); A
		a = ft_printf("INT_MAX: %d", INT_MAX); A
	#endif

	#ifdef T_DD
    	a = ft_printf("Hello"); A
    	a = ft_printf("Hello"); A
    	a = ft_printf("Hello"); A
    	a = ft_printf("Hello"); A
    	a = ft_printf("Hello"); A
    	a = ft_printf("Hello"); A
	#endif
}
