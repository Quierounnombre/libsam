#include "stdio.h"
#include <string.h>

size_t	ft__strlen(const char *s);
char	*ft__strcpy(const char *dst, const char *src);
int		ft__strcmp(const char *s1, const char *s2);

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
	printf("\n--------------------\n\n");
	printf("____strcmp(%s, %s) = %d\n", msg, cpy, strcmp(msg, cpy));
	printf("ft__strcmp(%s, %s) = %d\n", msg, cpy, strcmp(msg, cpy));
	cpy[5] = '0';
	printf("____strcmp(%s, %s) = %d\n", msg, cpy, strcmp(msg, cpy));
	printf("ft__strcmp(%s, %s) = %d\n", msg, cpy, strcmp(msg, cpy));
	cpy[2] = '/';
	printf("____strcmp(%s, %s) = %d\n", msg, cpy, strcmp(msg, cpy));
	printf("ft__strcmp(%s, %s) = %d\n", msg, cpy, strcmp(msg, cpy));
	printf("\n--------------------\n\n");
}