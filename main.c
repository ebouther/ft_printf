#include "ft_printf.h"

#include <stdio.h>

int main()
{
	unsigned int x = 3242334;

	ft_printf("char : '%c',\nstr: '%s',\n%%: '%%'\nint: '%010d' | x : '%x'\n", (char)'y', "dat'sastr", -42, x);
	printf("\n-----------------------------------------------\n");
	printf("char : '%c',\nstr: '%.4s',\n%%: '%%'\nint: '%010d' | x : '%x'\n", (char)'y', "dat'sastr", -42, x);
	printf("\nTEST:\n");
	//ft_printf("P : '%p'", &x);
	//printf("P : '%p'", &x);
	printf("{%}");
	printf("__\n");
	ft_printf("{%}");
	return (0);
}
