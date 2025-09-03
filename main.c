#include "stdio.h"
#include <string.h>

size_t	ft__strlen(const char *s);
char	*ft__strcpy(const char *dst, const char *src);

int	main(void)
{
	char	msg[12] = "hello_world";
	char	cpy[12];
	char	*ret;

	printf("strlen ===== %lu\n", strlen(msg));
	printf("ft__strlen = %lu\n", ft__strlen(msg));
	ret = strcpy(cpy, msg);
	printf("\n--------------------\n\n");
	printf("____strcpy(cpy %s, msg %s)\nptr_ret(%p && %p)ptr_cpy\n", cpy, msg, ret, cpy);
	memset(cpy, 0, 11);
	ret = ft__strcpy(cpy, msg);
	printf("ft__strcpy(cpy %s, msg %s)\nptr_ret(%p && %p)ptr_cpy\n", cpy, msg, ret, cpy);
}