#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include <string.h>

size_t	ft__strlen(const char *s);
char	*ft__strcpy(const char *dst, const char *src);
int		ft__strcmp(const char *s1, const char *s2);
int		ft__write(int fd, const char *s, size_t count);

int	main(void)
{
	char	msg[12] = "hello_world";
	char	cpy[12];
	char	*ret;
	int		i_ret;

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
	i_ret = write(1, cpy, 12);
	printf("   write____ = %d\n", i_ret);
	i_ret = ft__write(1, cpy, 12);
	printf("   ft__write = %d\n", i_ret);
	i_ret = write(1, msg, 2);
	printf("   write____ = %d\n", i_ret);
	i_ret = ft__write(1, msg, 2);
	printf("   ft__write = %d\n", i_ret);
}