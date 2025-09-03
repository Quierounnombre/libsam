#include "stdio.h"
#include <string.h>

size_t	ft__strlen(const char *s);

int	main(void)
{
	char	msg[12] = "hello_world";

	printf("strlen ===== %lu\n", strlen(msg));
	printf("ft__strlen = %lu\n", ft__strlen(msg));
}