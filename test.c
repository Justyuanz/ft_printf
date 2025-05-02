#include "libft.h"
#include <assert.h>
#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <bsd/string.h>

void	ft_atoi_test(void)
{
	assert(atoi(" -123junk") == ft_atoi(" -123junk"));
	assert(atoi(" +023junk") == ft_atoi(" +023junk"));
	assert(atoi(" 0") == ft_atoi(" 0"));
	assert(atoi("0042") == ft_atoi("0042"));
	assert(atoi("0x2a4") == ft_atoi("0x2a4"));
	assert(atoi("sa") == ft_atoi("sa"));
	assert(atoi("2147483648") == ft_atoi("2147483648"));
}

void	ft_bzero_test(void)
{
	char	a[50];
	size_t	n;

	n = 50;
	ft_bzero(a, n);
	for (size_t i = 0; i < 50; i++)
	{
		printf("%i", a[i]);
	}
}

void	mft_calloc_test(void)
{
	const unsigned char	*s1;
	const unsigned char	*s2;
	size_t				i;
	size_t				count;
	size_t				size;

	count = 0;
	size = sizeof(unsigned char);
	i = 0;
	s1 = calloc(count, size);
	s2 = ft_calloc(count, size);
	if (s1 == NULL || s2 == NULL)
		return;
	while (i < count * size)
	{
		if (s1[i] != s2[i])
		{
			free((void *)s1);
			free((void *)s2);
			printf("mismatch!");
		}
		i++;
	}
	free((void *)s1);
	free((void *)s2);
	printf("match!");
}

void	ft_isalnum_test(void)
{
	int	a;
	int	b;
	int	e;
	int	c;
	int	d;

	a = ' ';
	b = '5';
	e = 5;
	c = 'A';
	d = 'u';
	printf("%d ", ft_isalnum(a));
	printf("%d\n", isalnum(a));
	printf("%d ", ft_isalnum(b));
	printf("%d\n", isalnum(b));
	printf("%d ", ft_isalnum(e));
	printf("%d\n", isalnum(e));
	printf("%d ", ft_isalnum(e));
	printf("%d\n", isalnum(e));
	printf("%d ", ft_isalnum(c));
	printf("%d\n", isalnum(c));
	printf("%d ", ft_isalnum(d));
	printf("%d\n", isalnum(d));
}

void	ft_isalpha_test(void)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = ' ';
	b = '5';
	c = 'A';
	d = 'u';
	printf("%d ", ft_isalpha(a));
	printf("%d\n", isalpha(a));
	// system-specific or compiler-specific details that cause isalpha() to return a different non-zero value,
	//such as 1024 printf("%d ", ft_isalpha(b));
	printf("%d\n", isalpha(b));
	printf("%d ", ft_isalpha(c));
	printf("%d\n", isalpha(c));
	printf("%d ", ft_isalpha(d));
	printf("%d\n", isalpha(d));
}

void	ft_isascii_test(void)
{
	int	a;
	int	b;
	int	e;
	int	c;
	int	d;

	a = ' ';
	b = '5';
	e = 5;
	c = 150;
	d = 153;
	printf("%d ", ft_isascii(a));
	printf("%d\n", isascii(a));
	// Original ASCII contains unsigned (or positive) values from 0 to 127 (128 characters). Extended ASCII uses 8 bits and therefore has 256 potential values.
	printf("%d ", ft_isascii(b));
	printf("%d\n", isascii(b));
	printf("%d ", ft_isascii(e));
	printf("%d\n", isascii(e));
	printf("%d ", ft_isascii(c));
	printf("%d\n", isascii(c));
	printf("%d ", ft_isascii(d));
	printf("%d\n", isascii(d));
}

void	ft_isdigit_test(void)
{
	int	a;
	int	b;
	int	e;
	int	c;
	int	d;

	a = ' ';
	b = '5';
	e = 5;
	c = 'A';
	d = 'u';
	printf("%d ", ft_isdigit(a));
	printf("%d\n", isdigit(a));
	// system-specific or compiler-specific details that cause isalpha() to return a different non-zero value,
	//such as 1024 printf("%d ", ft_isdigit(b));
	printf("%d\n", isdigit(b));
	printf("%d ", ft_isdigit(e));
	printf("%d\n", isdigit(e));
	// the computer reads it as asscii value 5 while not putting ' ',
	//which is "Enquiry" in this case printf("%d ", ft_isdigit(e));
	printf("%d\n", isdigit(e));
	printf("%d ", ft_isdigit(c));
	printf("%d\n", isdigit(c));
	printf("%d ", ft_isdigit(d));
	printf("%d\n", isdigit(d));
}

void	ft_isprint_test(void)
{
	int	a;
	int	b;
	int	e;
	int	c;
	int	d;

	a = ' ';
	b = '5';
	e = 5;
	c = 128;
	d = 22;
	printf("%d ", ft_isprint(a));
	printf("%d\n", isprint(a));
	printf("%d ", ft_isprint(b));
	printf("%d\n", isprint(b));
	printf("%d ", ft_isprint(e));
	printf("%d\n", isprint(e));
	printf("%d ", ft_isprint(c));
	printf("%d\n", isprint(c));
	printf("%d ", ft_isprint(d));
	printf("%d\n", isprint(d));
}

void	ft_itoa_test(void)
{
	int		i;
	char	*str;

	i = -12345;
	str = ft_itoa(i);
	printf("%s", str);
	free(str);
}

void	ft_memchr_test(void)
{
	const char	*s = "This is isg";

	// printf("%.11s", (char  *)ft_memchr(s, c, n));
	assert(memchr(s, 'i', 2) == ft_memchr(s, 'i', 2));
	assert(memchr(s, 'i', 3) == ft_memchr(s, 'i', 3));
	assert(memchr(s, 'i', 10) == ft_memchr(s, 'i', 10));
	assert(memchr(s, 'Y', 11) == ft_memchr(s, 'Y', 11));
}

void	ft_memcmp_test(void)
{
	const void	*s1 = "This is s1";
	const void	*s2 = "This is s2";

	assert(memcmp(s1, s2, 11) == ft_memcmp(s1, s2, 11));
	assert(memcmp(s1, s2, 10) == ft_memcmp(s1, s2, 10));
	assert(memcmp(s1, s2, 5) == ft_memcmp(s1, s2, 5));
	assert(memcmp(s1, s2, 0) == ft_memcmp(s1, s2, 0));
}

void	ft_memcpy_test(void)
{
	char	dst[] = "";
	char	dst1[] = "";
	char	*src;
	size_t	n;

	src = "456789";
	n = 3;
	printf("%s\n", (char *)memcpy(dst, src, n));
	printf("%s\n", (char *)ft_memcpy(dst1, src, n));
	for (size_t i = 0; i < n; i++)
	{
		printf("%c", dst[i]);
	}
}

void	ft_memmove_test(void)
{
	char	dest[50] = "";
	char	*src;
	size_t	n;

	src = "fdfgdffd";
	n = 5;
	printf("%.5s", (char *)ft_memmove(dest, src, n));
}

void	ft_memset_test(void)
{
	char	a[50];
	int		c;
	size_t	n;

	c = '0';
	n = 4;
	a[4] = '\0';
	// printf("%.3s", (char *)memset(a, c, n));
	printf("%s", (char *)ft_memset(a, c, n));
}

void	ft_split_test(void)
{
	char const	*s;
	char		c;
	char		**arr;
	int			i;

	s = ",Hello,,this is,,a,,test,,hah";
	c = 0;
	arr = ft_split(s, c);
	i = 0;
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_strchr_test(void)
{
	const char	*s = "THIS IS ISH";
	char		c;

	c = 'S';
	printf("%s", ft_strchr(s, c));
	assert(strchr(s, c) == ft_strchr(s, c));
}

void	ft_strdup_test(void)
{
	const char	*s1 = "";
	char		*origin;
	char		*mine;

	origin = strdup(s1);
	mine = ft_strdup(s1);
	assert(strcmp(origin, mine) == 0);
	free(origin);
	free(mine);
}

void	ft_ttoupper(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
	{
		*c -= 32;
	}
}

void	ft_ttolower(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'A' && *c <= 'Z')
	{
		*c += 32;
	}
}

void	ft_striteri_test(void)
{
	char	s[] = "This is original";

	ft_striteri(s, ft_ttoupper);
	printf("%s\n", s);
	ft_striteri(s, ft_ttolower);
	printf("%s\n", s);
}

void	ft_strjoin_test(void)
{
	char const	*s1;
	char const	*s2;
	char		*expecteds3;
	char		*result;
	size_t		len;

	s1 = "";
	s2 = " ";
	expecteds3 = " ";
	result = ft_strjoin(s1, s2);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	assert(ft_strncmp(expecteds3, result, len) == 0);
}

void	ft_strlcat_test(void)
{
	char		dst[50] = "Hello";
	char		dst1[50] = "World";
	const char	*src = "is here";
	char		dst2[50] = "Hello";
	char		dst3[50] = "Hello";
	char		dst4[50] = "Hello";
	char		dst5[50] = "Hello";
	char		dst6[50] = "Hello";
	char		dst7[50] = "Hello";

	assert(strlcat(dst, src, 20) == ft_strlcat(dst1, src, 20));
	printf("%lu\n", ft_strlcat(dst, src, 4));
	printf("%s", dst);
	assert(strlcat(dst2, src, 10) == ft_strlcat(dst3, src, 10));
	assert(strlcat(dst4, src, 1) == ft_strlcat(dst5, src, 1));
	assert(strlcat(dst6, src, 0) == ft_strlcat(dst7, src, 0));
}

void	ft_strlcpy_test(void)
{
	char		dst[50];
	const char	src[] = "This is src";
	char		dst1[50];
	const char	src1[] = "This is src";
	char		dst2[50];
	const char	src2[] = "This is src";
	char		dst3[50];
	const char	src3[] = "";
	size_t		size;
	size_t		size1;
	size_t		size2;
	size_t		size3;

	size = sizeof(src);
	size1 = 0;
	size2 = 5;
	size3 = 5;
	ft_strlcpy(dst, src, size);
	printf("%s\n", dst);
	ft_strlcpy(dst1, src1, size1);
	printf("%s\n", dst1);
	ft_strlcpy(dst2, src2, size2);
	printf("%s\n", dst2);
	ft_strlcpy(dst3, src3, size3);
	printf("%s\n", dst3);
}

void	ft_strlen_test(void)
{
	const char	*a;
	const char	*b;
	const char	*c;
	const char	*d;
	const char	*e;

	a = "sgfhdf";
	b = "";
	c = "  ";
	d = "fdg  53";
	e = "12";
	printf("%lu ", ft_strlen(a));
	printf("%lu\n", strlen(a));
	printf("%lu ", ft_strlen(b));
	printf("%lu\n", strlen(b));
	printf("%lu ", ft_strlen(c));
	printf("%lu\n", strlen(c));
	printf("%lu ", ft_strlen(d));
	printf("%lu\n", strlen(d));
	printf("%lu ", ft_strlen(e));
	printf("%lu\n", strlen(e));
}

char	ft_ttoupper1(unsigned int i, char c)
{
	(void)i;
	if ((unsigned char)c >= 'a' && (unsigned char)c <= 'z')
	{
		return (c - 32);
	}
	return (c);
}

char	ft_ttolower1(unsigned int i, char c)
{
	(void)i;
	if ((unsigned char)c >= 'A' && (unsigned char)c <= 'Z')
	{
		return (c + 32);
	}
	return (c);
}

void	ft_strmapi_test(void)
{
	char const	*s;
	char		*result;

	s = "This is original";
	result = ft_strmapi(s, ft_ttoupper1);
	free(result);
	result = ft_strmapi(s, ft_ttolower1);
	printf("%s", result);
	free(result);
}

void	ft_strncmp_test(void)
{
	const char	*s1 = "asdffg";
	const char	*s2 = "asdfg";

	assert(ft_strncmp(s1, s2, 5) == strncmp(s1, s2, 5));
	assert(ft_strncmp(s1, s2, 2) == strncmp(s1, s2, 2));
	assert(ft_strncmp(s1, s2, 6) == strncmp(s1, s2, 6));
	assert(ft_strncmp(s1, s2, 0) == strncmp(s1, s2, 0));
}

void	ft_strnstr_test(void)
{
	const char	*haystack = "dsfsd";

	// printf("%s", strnstr(haystack, "ds", 3));
	// printf("%s", ft_strnstr(haystack, "ds", 3));
	assert(strnstr(haystack, "fs", 5) == ft_strnstr(haystack, "fs", 5));
	assert(strnstr(haystack, "fs", 1) == ft_strnstr(haystack, "fs", 1));
	assert(strnstr(haystack, "ds", 0) == ft_strnstr(haystack, "ds", 0));
	assert(strnstr(haystack, "", 3) == ft_strnstr(haystack, "", 3));
	assert(strnstr(haystack, "a", 5) == ft_strnstr(haystack, "a", 5));
}

void	ft_strrchr_test(void)
{
	const char	*s = "THIS IS ISH";

	// printf("%s", ft_strrchr(s, 'I'));
	assert(strrchr(s, 'I') == ft_strrchr(s, 'I'));
	assert(strrchr(s, 'Z') == ft_strrchr(s, 'Z'));
	assert(strrchr(s, '\0') == ft_strrchr(s, '\0'));
}

void	ft_strtrim_test(void)
{
	char const	*s1;
	char const	*set;
	char		*str;

	s1 = "";
	set = "2";
	str = ft_strtrim(s1, set);
	printf("%s", str);
	free(str);
}

void	ft_substr_test(void)
{
	char const		*s;
	unsigned int	start;
	size_t			len;
	char			*expected;
	char			*result;

	s = "Apple pie";
	start = 5;
	len = 10;
	expected = " pie";
	result = ft_substr(s, start, len);
	assert(ft_strncmp(expected, result, len) == 0);
	free(result);
}

void	ft_tolower_test(void)
{
	int	c;
	int	b;

	c = 97;
	b = 97;
	printf("%c", (unsigned char)ft_tolower(c));
	printf("%c", (unsigned char)tolower(b));
}

void	ft_toupper_test(void)
{
	int	c;
	int	b;

	c = -1;
	b = -1;
	printf("%c", (unsigned char)ft_toupper(c));
	printf("%c", (unsigned char)toupper(b));
}

void	ft_putchar_fd_test(void)
{
	char	a;
	int		fd;

	a = '\0';
	fd = open("bar.txt", O_WRONLY | O_CREAT);
	if (fd == -1)
	{
		printf("FAILED\n");
	}
	else
	{
		ft_putchar_fd(a, fd);
	}
	close(fd);
}

void	ft_putendl_fd_test(void)
{
	char	*s;
	int		fd;

	s = "ABCDE";
	fd = open("dl.txt", O_RDWR | O_CREAT, 0777);
	if (fd == -1)
	{
		printf("failed");
	}
	else
	{
		ft_putendl_fd(s, fd);
	}
	close(fd);
}

void	ft_putnbr_fd_test(void)
{
	int	n;
	int	fd;

	n = 0;
	fd = open("nbr.txt", O_RDWR | O_TRUNC | O_CREAT, 0777);
	if (fd == -1)
	{
		printf("failed");
	}
	else
	{
		ft_putnbr_fd(n, fd);
	}
	close(fd);
}

void	ft_putstr_fd_test(void)
{
	char	*s;
	int		fd;

	s = "abcde";
	fd = open("bar.txt", O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (fd == -1)
	{
		printf("failed\n");
	}
	else
	{
		ft_putstr_fd(s, fd);
	}
	close(fd);
}

int	main(void)
{
		printf("Testing ft_atoi...\n");
		ft_atoi_test();
		printf("\n");

		printf("Testing ft_bzero...\n");
		ft_bzero_test();
		printf("\n");
		printf("\n");

		printf("Testing ft_calloc...\n");
		printf("\n");
		mft_calloc_test();
		printf("\n");

		printf("Testing ft_isalnum...\n");
		ft_isalnum_test();
		printf("\n");

		printf("Testing ft_isalpha...\n");
		ft_isalpha_test();
		printf("\n");

		printf("Testing ft_isascii...\n");
		ft_isascii_test();
		printf("\n");

		printf("Testing ft_isdigit...\n");
		ft_isdigit_test();
		printf("\n");

		printf("Testing ft_isprint...\n");
		ft_isprint_test();
		printf("\n");

		printf("Testing ft_itoa...\n");
		ft_itoa_test();
		printf("\n");
		printf("\n");

		printf("Testing ft_memchr...\n");
		ft_memchr_test();
		printf("\n");

		printf("Testing ft_memcmp...\n");
		ft_memcmp_test();
		printf("\n");

		printf("Testing ft_memcpy...\n");
		ft_memcpy_test();
		printf("\n");
		printf("\n");

		printf("Testing ft_memmove...\n");
		ft_memmove_test();
		printf("\n");
		printf("\n");

		printf("Testing ft_memset...\n");
		ft_memset_test();
		printf("\n");
		printf("\n");

		printf("Testing ft_split...\n");
		ft_split_test();
		printf("\n");

		printf("Testing ft_strchr...\n");
		ft_strchr_test();
		printf("\n");
		printf("\n");

		printf("Testing ft_strdup...\n");
		ft_strdup_test();
		printf("\n");

		printf("Testing ft_striteri...\n");
		ft_striteri_test();
		printf("\n");

		printf("Testing ft_strjoin...\n");
		ft_strjoin_test();
		printf("\n");

		printf("Testing ft_strlcat...\n");
		ft_strlcat_test();
		printf("\n");
		printf("\n");

		printf("Testing ft_strlcpy...\n");
		ft_strlcpy_test();
		printf("\n");

		printf("Testing ft_strlen...\n");
		ft_strlen_test();
		printf("\n");

		printf("Testing ft_strmapi...\n");
		ft_strmapi_test();
		printf("\n");
		printf("\n");

		printf("Testing ft_strncmp...\n");
		ft_strncmp_test();
		printf("\n");

		printf("Testing ft_strnstr...\n");
		ft_strnstr_test();
		printf("\n");

		printf("Testing ft_strrchr...\n");
		ft_strrchr_test();
		printf("\n");

		printf("Testing ft_strtrim...\n");
		ft_strtrim_test();
		printf("\n");

		printf("Testing ft_substr...\n");
		ft_substr_test();
		printf("\n");

		printf("Testing ft_tolower...\n");
		ft_tolower_test();
		printf("\n");

		printf("Testing ft_toupper...\n");
		ft_toupper_test();
		printf("\n");

		printf("Testing ft_putchar_fd...\n");
		ft_putchar_fd_test();
		printf("\n");

		printf("Testing ft_putendl_fd...\n");
		ft_putendl_fd_test();
		printf("\n");

		printf("Testing ft_putnbr_fd...\n");
		ft_putnbr_fd_test();
		printf("\n");

		printf("Testing ft_putstr_fd...\n");
		ft_putstr_fd_test();
		printf("\n");

		printf("\n🎉 If you see this message, all tests finished without crashing!\n");
		return (0);
}