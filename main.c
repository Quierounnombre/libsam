#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include <string.h>
#include <fcntl.h>
#include <errno.h>

size_t	ft__strlen(const char *s);
char	*ft__strcpy(const char *dst, const char *src);
int		ft__strcmp(const char *s1, const char *s2);
int		ft__write(int fd, const char *s, size_t count);
int		ft__read(int fd, char *buf, size_t count);

int	main(void)
{
	char	msg[12] = "hello_world";
	char	cpy[12];
	char	buf[500];
	char	*ret;
	int		i_ret;
	
	{
		printf("strlen ===== %lu\n", strlen(msg));
		printf("ft__strlen = %lu\n", ft__strlen(msg));
	}
	printf("\n--------------------\n\n");
	{
		ret = strcpy(cpy, msg);
		printf("____strcpy(cpy %s, msg %s)\nptr_ret(%p && %p)ptr_cpy\n", cpy, msg, ret, cpy);
		memset(cpy, 0, 11);
		ret = ft__strcpy(cpy, msg);
		printf("ft__strcpy(cpy %s, msg %s)\nptr_ret(%p && %p)ptr_cpy\n", cpy, msg, ret, cpy);
	}
	printf("\n--------------------\n\n");
	{
		printf("____strcmp(%s, %s) = %d\n", msg, cpy, strcmp(msg, cpy));
		printf("ft__strcmp(%s, %s) = %d\n", msg, cpy, strcmp(msg, cpy));
		cpy[5] = '0';
		printf("____strcmp(%s, %s) = %d\n", msg, cpy, strcmp(msg, cpy));
		printf("ft__strcmp(%s, %s) = %d\n", msg, cpy, strcmp(msg, cpy));
		cpy[2] = '/';
		printf("____strcmp(%s, %s) = %d\n", msg, cpy, strcmp(msg, cpy));
		printf("ft__strcmp(%s, %s) = %d\n", msg, cpy, strcmp(msg, cpy));
	}
	printf("\n--------------------\n\n");
	{
		i_ret = write(1, cpy, 12);
		printf("   write____ = %d\n", i_ret);
		i_ret = ft__write(1, cpy, 12);
		printf("   ft__write = %d\n", i_ret);
		i_ret = write(1, msg, 2);
		printf("   write____ = %d\n", i_ret);
		i_ret = ft__write(1, msg, 2);
		printf("   ft__write = %d\n", i_ret);

		i_ret = write(10, cpy, 12);
		printf("Error ____write = %d && errno = %d\n", i_ret, errno);
		i_ret = ft__write(10, cpy, 12);
		printf("Error ft__write = %d && errno = %d\n", i_ret, errno);
		
	}
	printf("\n--------------------\n\n");
	{
		int		fd;

		memset(buf, 0, 500);
		printf("____read(100) = \n");
		i_ret =	read(0, buf, 100);
		printf("result = %s\nBytes = %d\n", buf, i_ret);
		memset(buf, 0, 500);
		printf("ft__read(100) = \n");
		i_ret = ft__read(0, buf, 100);
		printf("result = %s\nBytes = %d\n", buf, i_ret);
		
		fd = open("Learning_links.txt", O_RDONLY);
		memset(buf, 0, 500);
		printf("____read(100) = \n");
		i_ret =	read(fd, buf, 100);
		printf("result = %s\nBytes = %d\n", buf, i_ret);
		close(fd);
		fd = open("Learning_links.txt", O_RDONLY);
		memset(buf, 0, 500);
		printf("ft__read(100) = \n");
		i_ret = ft__read(fd, buf, 100);
		printf("result = %s\nBytes = %d\n", buf, i_ret);
		close(fd);
		
		i_ret = read(fd, buf, 100);
		printf("____read %d && errno %d\n", i_ret, errno);
		i_ret = ft__read(fd, buf, 100);
		printf("ft__read %d && errno %d\n", i_ret, errno);
	}	
}