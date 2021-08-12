/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <ccorliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:19:27 by ccorliss          #+#    #+#             */
/*   Updated: 2020/12/07 19:50:26 by ccorliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "stdio.h"
# define BUFFER_SIZE 512

int		strlen_test(char *str)
{
	int	ret1;
	int	ret2;

	ret1 = ft_strlen(str);
	ret2 = strlen(str);
	printf("%d %d ", ret1, ret2);
	if (ret1 == ret2)
		printf("ok\n");
	else
		printf("ko\n");
	return (1);
}

int		strcpy_test(char *src)
{
	char	dest1[BUFFER_SIZE];
	char	dest2[BUFFER_SIZE];

	bzero(dest1, BUFFER_SIZE);
	bzero(dest2, BUFFER_SIZE);
	ft_strcpy(dest1, src);
	strcpy(dest2, src);
	printf("%s\n%s ", dest1, dest2);
	if (!strcmp(dest1, dest2))
		printf("ok\n");
	else
		printf("ko\n");
	return (1);
}

int		strcmp_test(char *s1, char *s2)
{
	int	ret1;
	int	ret2;

	ret1 = ft_strcmp(s1, s2);
	ret2 = strcmp(s1, s2);
	printf("%d %d ", ret1, ret2);
	if (ret1 == ret2)
		printf("ok\n");
	else
		printf("ko\n");
	return (1);
}

int		write_test(char *str)
{
	int		ft_write_pipe[2];
	char	buf[BUFFER_SIZE];
	int		ret;

	bzero(buf, BUFFER_SIZE);
	if (pipe(ft_write_pipe) < 0)
		exit(EXIT_FAILURE);
	fcntl(ft_write_pipe[0], F_SETFL, O_NONBLOCK);
	write(ft_write_pipe[1], str, strlen(str));
	ret = read(ft_write_pipe[0], buf, BUFFER_SIZE);
	buf[ret] = '\0';
	printf("%s\n%s ", buf, str);
	if (!strcmp(buf, str))
		printf("ok\n");
	else
		printf("ko\n");
	close(ft_write_pipe[1]);
	close(ft_write_pipe[0]);
	return (1);
}

int		read_test(char *str)
{
	int		ft_read_pipe[2];
	char	buf[BUFFER_SIZE];
	int		ret;

	bzero(buf, BUFFER_SIZE);
	if (pipe(ft_read_pipe) < 0)
		exit(EXIT_FAILURE);
	fcntl(ft_read_pipe[0], F_SETFL, O_NONBLOCK);
	write(ft_read_pipe[1], str, strlen(str));
	ret = ft_read(ft_read_pipe[0], buf, BUFFER_SIZE);
	buf[ret] = '\0';
	printf("%s\n%s ", buf, str);
	if (!strcmp(buf, str))
		printf("ok\n");
	else
		printf("ko\n");
	close(ft_read_pipe[1]);
	close(ft_read_pipe[0]);
	return (1);
}

int		strdup_test(char *str)
{
	char	*str1;
	char	*str2;

	str1 = ft_strdup(str);
	str2 = strdup(str);
	printf("%s\n%s ", str1, str2);
	if (!strcmp(str1, str2))
		printf("ok\n");
	else
		printf("ko\n");
	free(str1);
	free(str2);
	return (1);
}

int		main(void)
{
	/*
	** FT_STRLEN
	*/
	printf("%-12s :  \n", "ft_strlen.s");
	strlen_test("hello");
	strlen_test("");
	strlen_test("gfygf uehyeh  eiy eh eei a");
	strlen_test("Lwgbwrg  e hehg gbeiwoww bbgevtyiuioosskbbgbgeeui  bbakoirt hajbbieopw;k,fmjpmjwfowfcwcwq.");
	strlen_test("        ");
	printf("\n\n");

	/*
	** FT_STRCPY
	*/
	printf("%-12s :  \n", "ft_strcpy.s");
	strcpy_test("qwer");
	strcpy_test("");
	strcpy_test("gfygf uehyeh  eiy eh eei a");
	strcpy_test("Lwgbwrg  e hehg gbeiwoww bbgevtyiuioosskbbgbgeeui  bbakoirt hajbbieopw;k,fmjpmjwfowfcwcwq.");
	strcpy_test("        ");
	printf("\n\n");

	/*
	** FT_STRCMP
	*/
	printf("%-12s :  \n", "ft_strcmp.s");
	strcmp_test("hello", "hello");
	strcmp_test("abcdef", "qazef");
	strcmp_test("", "abc");
	strcmp_test("gfygf uehyeh  eiy eh eei a", "   ");
	strcmp_test("", "");
	strcmp_test("qwer", "");
	strcmp_test("Lwgbwrg  e hehg gbeiwoww bbgevtyiuioosskbbgbgeeui  bbakoirt hajbbieopw;k,fmjpmjwfowfcwcwq.", "Lwgbwrg  e hehg gbeiwoww bbgevtyiuioosskbbgbgeeui  bbakoirt hajbbieopw;k,fmjpmjwfowfcwcwq.");
	printf("\n\n");

	/*
	** FT_WRITE
	*/
	printf("%-12s :  \n", "ft_write.s");
	write_test("");
	write_test("hello");
	write_test("test world");
	write_test("Lwgbwrg  e hehg gbeiwoww bbgevtyiuioosskbbgbgeeui  bbakoirt hajbbieopw;k,fmjpmjwfowfcwcwq.");
	printf("\n\n");

	/*
	** FT_READ
	*/

	printf("%-12s :  \n", "ft_read.s");
	read_test("hello");
	read_test("gfygf uehyeh  eiy eh eei a");
	read_test("");
	read_test("Lwgbwrg  e hehg gbeiwoww bbgevtyiuioosskbbgbgeeui  bbakoirt hajbbieopw;k,fmjpmjwfowfcwcwq.");
	printf("\n\n");

	/*
	** FT_STRDUP
	*/
	printf("%-12s :  \n", "ft_strdup.s");
	strdup_test("hello");
	strdup_test("hello world");
	strdup_test("");
	strdup_test("Lwgbwrg  e hehg gbeiwoww bbgevtyiuioosskbbgbgeeui  bbakoirt hajbbieopw;k,fmjpmjwfowfcwcwq.");
	printf("\n");
}
