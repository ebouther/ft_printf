#include "ft_printf.h"

#include <stdio.h>
#include <limits.h>

int main()
{
	int	len = 0;
	unsigned int x = 3242334;
	char c;

	setbuf(stdout, NULL);

	//printf("{%-15Z}", 123);
	//printf("{%10R}", 123);
	//printf("% Zoooo");
	//len = ft_printf("{%-15Z}", 123);
	//len = ft_printf("%#x", 42);
	//len = ft_printf("% Zoooo");
	//ft_printf("{%10R}", 123);
//ft_printf("char : '%c',\nstr: '%s',\n%%: '%%'\nint: '%010d' | x : '%x'\n", (char)'y', "dat'sastr", -42, x);
	//printf("\n-----------------------------------------------\n");
	//printf("char : '%c',\nstr: '%.4s',\n%%: '%%'\nint: '%010d' | x : '%x'\n", (char)'y', "dat'sastr", -42, x);
	ft_printf("'%.4s'", "123456789");
	return (len);
}
